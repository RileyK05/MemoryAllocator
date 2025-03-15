#include "FixedPool.h"

FixedPool::FixedPool() {
    stored = 0;
    poolSize = new Node[FIXED_POOL];
    current = &poolSize[0];
    head = current;
    tail = current;

    for (size_t i = 0; i < FIXED_POOL - 1; i++) {
        poolSize[i].next = &poolSize[i + 1];
    }

    poolSize[FIXED_POOL - 1].next = nullptr;
}

FixedPool::~FixedPool() {
    delete[] poolSize;
    delete head;
    delete tail;
    delete current;
}

Node* FixedPool::addCompany(Company nCompany) {
    if (stored >= FIXED_POOL) {
        std::cerr << "Error: Not enough space in pool\n";
        return nullptr;
    }

    Node* newNode = &poolSize[stored++];
    newNode->company = nCompany;

    if (head == nullptr) {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        else {
            tail = newNode;
        }

        current->next = newNode;
    }

    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        temp = temp->next;
    }
    current = temp;

    return newNode;
}

Node* FixedPool::removeCompany(Company nCompany) {
    Node* temp = head;
    while (temp) {
        if (temp->company.ticker == nCompany.ticker && temp->company.insertId == nCompany.insertId) {
            if (temp == head) {
                head = temp->next;
            }

            if (temp == tail) {
                tail = temp->prev;
            }

            if (temp == current) {
                current = temp->prev ? temp->prev : temp->next;
            }

            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            }

            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }

            temp->next = nullptr;
            temp->prev = nullptr;

            stored--;

            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Node* FixedPool::getCompany(int id, char tckr[TICKER_SIZE]) {
    Node* temp = head;
    while (temp) {
        if (temp->insertId == id && temp->company.ticker == tckr) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Node* FixedPool::editCompany(int id, char tckr[TICKER_SIZE], Company edits) {
    Node* temp = head;
    while (temp) {
        if (temp->insertId == id && temp->company.ticker == tckr) {
            temp->company = edits;
        }
    }
}
