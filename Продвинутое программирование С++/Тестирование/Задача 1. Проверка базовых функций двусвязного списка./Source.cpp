#include <catch2/catch_all.hpp>

#include <cstdint>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};

class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

// ================================
//          UNIT-ТЕСТЫ
// ================================

TEST_CASE("Empty: свежесозданный список пуст", "[Empty]") {
    List list;
    REQUIRE(list.Empty() == true);
}

TEST_CASE("Empty: список с элементами не пуст", "[Empty]") {
    List list;
    SECTION("после PushFront") {
        list.PushFront(10);
        REQUIRE(list.Empty() == false);
    }
    SECTION("после PushBack") {
        list.PushBack(20);
        REQUIRE(list.Empty() == false);
    }
    SECTION("после нескольких вставок") {
        list.PushFront(1);
        list.PushBack(2);
        list.PushFront(3);
        REQUIRE(list.Empty() == false);
    }
}

TEST_CASE("Empty: список становится пустым после удаления всех элементов", "[Empty]") {
    List list;
    list.PushBack(1);
    list.PushBack(2);

    SECTION("удаление через PopFront") {
        list.PopFront();
        REQUIRE(list.Empty() == false);
        list.PopFront();
        REQUIRE(list.Empty() == true);
    }
    SECTION("удаление через PopBack") {
        list.PopBack();
        REQUIRE(list.Empty() == false);
        list.PopBack();
        REQUIRE(list.Empty() == true);
    }
    SECTION("смешанное удаление") {
        list.PopFront();
        list.PopBack();
        REQUIRE(list.Empty() == true);
    }
}

TEST_CASE("Empty: список пуст после Clear", "[Empty]") {
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.Clear();
    REQUIRE(list.Empty() == true);
}

TEST_CASE("Size: свежесозданный список имеет размер 0", "[Size]") {
    List list;
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Size: корректность после PushFront", "[Size]") {
    List list;
    SECTION("один элемент") {
        list.PushFront(10);
        REQUIRE(list.Size() == 1);
    }
    SECTION("три элемента") {
        list.PushFront(1);
        list.PushFront(2);
        list.PushFront(3);
        REQUIRE(list.Size() == 3);
    }
}

TEST_CASE("Size: корректность после PushBack", "[Size]") {
    List list;
    SECTION("один элемент") {
        list.PushBack(10);
        REQUIRE(list.Size() == 1);
    }
    SECTION("пять элементов") {
        for (int i = 0; i < 5; ++i)
            list.PushBack(i);
        REQUIRE(list.Size() == 5);
    }
}

TEST_CASE("Size: корректность после смешанных Push", "[Size]") {
    List list;
    list.PushFront(1);
    list.PushBack(2);
    list.PushFront(3);
    list.PushBack(4);
    REQUIRE(list.Size() == 4);
}

TEST_CASE("Size: корректность после PopFront", "[Size]") {
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);

    list.PopFront();
    REQUIRE(list.Size() == 2);

    list.PopFront();
    REQUIRE(list.Size() == 1);

    list.PopFront();
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Size: корректность после PopBack", "[Size]") {
    List list;
    list.PushBack(10);
    list.PushBack(20);

    list.PopBack();
    REQUIRE(list.Size() == 1);

    list.PopBack();
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Size: корректность после Clear", "[Size]") {
    List list;
    for (int i = 0; i < 10; ++i)
        list.PushBack(i);
    list.Clear();
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Clear: очистка пустого списка не вызывает ошибок", "[Clear]") {
    List list;
    list.Clear();
    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Clear: очистка списка с одним элементом", "[Clear]") {
    List list;
    list.PushBack(42);
    list.Clear();
    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Clear: очистка списка с несколькими элементами", "[Clear]") {
    List list;
    list.PushFront(1);
    list.PushBack(2);
    list.PushFront(3);
    list.PushBack(4);
    list.Clear();
    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Clear: список работоспособен после очистки", "[Clear]") {
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.Clear();

    SECTION("можно добавлять после Clear") {
        list.PushBack(10);
        list.PushBack(20);
        REQUIRE(list.Size() == 2);
        REQUIRE(list.Empty() == false);
    }
    SECTION("можно добавлять и удалять после Clear") {
        list.PushFront(5);
        list.PushBack(15);
        REQUIRE(list.PopFront() == 5);
        REQUIRE(list.PopBack() == 15);
        REQUIRE(list.Empty() == true);
    }
}

TEST_CASE("Clear: многократная очистка", "[Clear]") {
    List list;
    list.PushBack(1);
    list.Clear();

    list.PushBack(2);
    list.PushBack(3);
    list.Clear();

    list.PushBack(4);
    list.Clear();

    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Комплексный сценарий: Empty и Size на разных этапах", "[Integration]") {
    List list;

    REQUIRE(list.Empty());
    REQUIRE(list.Size() == 0);

    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);

    REQUIRE_FALSE(list.Empty());
    REQUIRE(list.Size() == 3);

    list.PopFront();
    REQUIRE(list.Size() == 2);

    list.Clear();
    REQUIRE(list.Empty());
    REQUIRE(list.Size() == 0);

    list.PushFront(100);
    REQUIRE(list.Size() == 1);
    REQUIRE_FALSE(list.Empty());

    list.PopBack();
    REQUIRE(list.Empty());
    REQUIRE(list.Size() == 0);
}
