#pragma once

#include <string>
#include <stdexcept>

template<class TValueType>
class List
{
private:
    template<class TNodeValueType>
    class Node
    {
    private:
        TNodeValueType* Value;
        Node<TNodeValueType>* Next;

    public:
        Node(TNodeValueType* value) : Value(value), Next(nullptr) { }

        inline TNodeValueType* GetValue() const { return this->Value; }

        virtual ~Node() {
            delete Value;
        }

        friend class List<TNodeValueType>;
    };

    Node<TValueType>* First;
    Node<TValueType>* Last;
    mutable Node<TValueType>* Current;
    

public:
    List() : First(nullptr), Last(nullptr), Current(nullptr) {}

    void Add(TValueType* value)
    {
        Node<TValueType>* newNode = new Node<TValueType>(value);

        if (First == nullptr)
        {
            First = newNode;
            Last = newNode;
        }
        else
        {
            Last->Next = newNode;
            Last = newNode;
        }
    }

    void Start() const
    {
        Current = nullptr;
    }

    TValueType* Next() const
    {
        Current = Current == nullptr ? First : Current->Next;
        return Current == nullptr ? nullptr : Current->GetValue();
    }

    void Remove(const TValueType& value)
    {
        Node<TValueType>* currentNode = First;
        Node<TValueType>* previousNode = nullptr;

        while (currentNode)
        {
            TValueType* currentValue = currentNode->GetValue();

            if (*currentValue == value)
            {
                if (currentNode == First && currentNode == Last)
                {
                    First = nullptr;
                    Last = nullptr;
                }
                else
                {
                    if (currentNode == First)
                        First = currentNode->Next;

                    if (previousNode != nullptr)
                        previousNode->Next = currentNode->Next;
                }

                delete currentNode;

                return;
            }

            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        throw std::invalid_argument("Object for remove not found.");
    }

    void Clear()
    {
        Node<TValueType>* currentNode = First;

        while (currentNode)
        {
            Node<TValueType>* ptrNext = currentNode->Next;
            delete currentNode;

            currentNode = ptrNext;
        }

        First = nullptr;
        Last = nullptr;
        Current = nullptr;
    }

    virtual ~List() { Clear(); }
};
