#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <iostream>

/**
 * @brief ���� ��������� ���������, ���� ���� ��������������� unique_ptr � C++.
 *
 * UniquePtr �������� ��������� ��������������� ������ ��������� �� �������,
 * �� ���'��� ���� ��������, ���� ��������� �������� �������� �� ������� 䳿.
 *
 * @tparam T ��� ��'����, �� ���� ����� ��������.
 */
template <typename T>
class UniquePtr {
private:
    T* ptr; ///< �������� �� ��'���.

public:
    /**
     * @brief ����������� ����� UniquePtr.
     *
     * �������� ��'��� UniquePtr ���������� �� ��������� ��'���.
     *
     * @param p �������� �� ��'���, ���� ������� ���� �������.
     */
    UniquePtr(T* p) : ptr(p) {}

    /**
     * @brief ���������� ����� UniquePtr.
     *
     * ������� ���'���, �� ��� ����� �������� ��������.
     */
    ~UniquePtr() {
        delete ptr;
    }

    /**
     * @brief �������� �������� ��������.
     *
     * @return �������� �������� �� ��'���.
     */
    T* get() const {
        return ptr;
    }

    /**
     * @brief �������������� ��������� ������������.
     *
     * @return ��������� �� ��'����, �� ���� ����� �������� ��������.
     */
    T& operator*() const {
        return *ptr;
    }

    /**
     * @brief �������������� ��������� ������.
     *
     * @return �������� �� ��'���.
     */
    T* operator->() const {
        return ptr;
    }

    // �������� ��������� �� ���������
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
};

/**
 * @brief ���� ��������� ���������, ���� ���� ��������������� shared_ptr � C++.
 *
 * SharedPtr �������� ������ ��������� ��������������� ���� ������ �� �������,
 * �� ���'��� ���� �������� ����� ���� ���������� ������������.
 *
 * @tparam T ��� ��'����, �� ���� ����� ��������.
 */
template <typename T>
class SharedPtr {
private:
    T* ptr; ///< �������� �� ��'���.
    int* refCount; ///< �������� �� �������� ��������.

public:
    /**
     * @brief ����������� ����� SharedPtr.
     *
     * �������� ��'��� SharedPtr ���������� �� ��������� ��'���.
     * ˳������� �������� ������������ ��������� 1.
     *
     * @param p �������� �� ��'���, ���� ���� ���������.
     */
    SharedPtr(T* p) : ptr(p), refCount(new int(1)) {}

    /**
     * @brief ����������� ��������� ����� SharedPtr.
     *
     * ������ �������� �������� �� ����� �������� �� ��'���.
     *
     * @param other ����� SharedPtr, � ����� ��������� �������� �� ��������.
     */
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        (*refCount)++;
    }

    /**
     * @brief ���������� ����� SharedPtr.
     *
     * ������ �������� �������� �� ������� ���'���, ���� �������� ��� ��������.
     */
    ~SharedPtr() {
        (*refCount)--;
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
        }
    }

    /**
     * @brief �������������� ��������� ��������� ��� ����� SharedPtr.
     *
     * @param other ����� SharedPtr, � ����� ��������� �������� �� ��������.
     * @return SharedPtr � ��ﳺ� ��������� �� ���������.
     */
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            (*refCount)--;
            if (*refCount == 0) {
                delete ptr;
                delete refCount;
            }

            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    /**
     * @brief �������� �������� ��������.
     *
     * @return �������� �������� �� ��'���.
     */
    T* get() const {
        return ptr;
    }

    /**
     * @brief �������������� ��������� ������������.
     *
     * @return ��������� �� ��'����, �� ���� ����� �������� ��������.
     */
    T& operator*() const {
        return *ptr;
    }

    /**
     * @brief �������������� ��������� ������.
     *
     * @return �������� �� ��'���.
     */
    T* operator->() const {
        return ptr;
    }

    /**
     * @brief �������� ������� �������� ��'����.
     *
     * @return ˳������� �������� - ������� �������� ��'����.
     */
    int useCount() const {
        return *refCount;
    }
};

#endif // SMART_POINTER_H
