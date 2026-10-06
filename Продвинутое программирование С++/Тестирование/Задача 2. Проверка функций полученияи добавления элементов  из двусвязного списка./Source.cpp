#include <catch2/catch_all.hpp>

#include <stdexcept>

struct ListNode {
    int value;
    ListNode* prev;
    ListNode* next;

    ListNode(int val, ListNode* p = nullptr, ListNode* n = nullptr)
        : value(val), prev(p), next(n) {
    }
};

class List {
public:
    List() : m_size(0) {
        m_head = new ListNode(0);
        m_tail = new ListNode(0);
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }

    virtual ~List() {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() const { return m_size == 0; }
    unsigned long Size() const { return m_size; }

    void PushFront(int value) {
        ListNode* node = new ListNode(value, m_head, m_head->next);
        node->prev->next = node;
        node->next->prev = node;
        ++m_size;
    }

    void PushBack(int value) {
        ListNode* node = new ListNode(value, m_tail->prev, m_tail);
        node->prev->next = node;
        node->next->prev = node;
        ++m_size;
    }

    int PopFront() {
        if (Empty()) {
            throw std::runtime_error("list is empty");
        }
        ListNode* target = m_head->next;
        int ret = target->value;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        delete target;
        return ret;
    }

    int PopBack() {
        if (Empty()) {
            throw std::runtime_error("list is empty");
        }
        ListNode* target = m_tail->prev;
        int ret = target->value;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        delete target;
        return ret;
    }

    void Clear() {
        while (!Empty()) {
            ListNode* target = m_head->next;
            target->prev->next = target->next;
            target->next->prev = target->prev;
            --m_size;
            delete target;
        }
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


// ================================
//          UNIT-ТЕСТЫ
// ================================

TEST_CASE("PushBack adds element and size increases") {
    List lst;
    REQUIRE(lst.Empty() == true);
    REQUIRE(lst.Size() == 0);

    lst.PushBack(10);
    REQUIRE(lst.Empty() == false);
    REQUIRE(lst.Size() == 1);

    lst.PushBack(20);
    REQUIRE(lst.Size() == 2);
}

TEST_CASE("PushFront adds element and size increases") {
    List lst;
    lst.PushFront(5);
    REQUIRE(lst.Size() == 1);

    lst.PushFront(1);
    REQUIRE(lst.Size() == 2);
    int first = lst.PopFront();
    REQUIRE(first == 1);
}

TEST_CASE("PopFront on empty list throws") {
    List lst;
    REQUIRE_THROWS_AS(lst.PopFront(), std::runtime_error);
}

TEST_CASE("PopBack on empty list throws") {
    List lst;
    REQUIRE_THROWS_AS(lst.PopBack(), std::runtime_error);
}

TEST_CASE("PopFront removes correct element") {
    List lst;
    lst.PushBack(10);
    lst.PushBack(20);
    lst.PushBack(30);

    REQUIRE(lst.PopFront() == 10);
    REQUIRE(lst.Size() == 2);
    REQUIRE(lst.PopFront() == 20);
    REQUIRE(lst.Size() == 1);
    REQUIRE(lst.PopFront() == 30);
    REQUIRE(lst.Size() == 0);
}

TEST_CASE("PopBack removes correct element") {
    List lst;
    lst.PushBack(10);
    lst.PushBack(20);
    lst.PushBack(30);

    REQUIRE(lst.PopBack() == 30);
    REQUIRE(lst.Size() == 2);
    REQUIRE(lst.PopBack() == 20);
    REQUIRE(lst.Size() == 1);
    REQUIRE(lst.PopBack() == 10);
    REQUIRE(lst.Size() == 0);
}

TEST_CASE("Mixed Push/Pop operations") {
    List lst;
    lst.PushFront(1);
    lst.PushBack(2);
    lst.PushFront(0);
    REQUIRE(lst.Size() == 3);

    REQUIRE(lst.PopFront() == 0);
    REQUIRE(lst.PopBack() == 2);
    REQUIRE(lst.PopFront() == 1);
    REQUIRE(lst.Empty() == true);
}

TEST_CASE("Clear empties the list") {
    List lst;
    for (int i = 0; i < 5; ++i) {
        lst.PushBack(i);
    }
    REQUIRE(lst.Size() == 5);

    lst.Clear();
    REQUIRE(lst.Empty() == true);
    REQUIRE(lst.Size() == 0);

    lst.PushBack(100);
    REQUIRE(lst.Size() == 1);
    REQUIRE(lst.PopBack() == 100);
}
