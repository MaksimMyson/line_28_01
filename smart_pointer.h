#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <iostream>

/**
 * @brief Клас розумного покажчика, який імітує функціональність unique_ptr в C++.
 *
 * UniquePtr дозволяє власникові використовувати ресурс самостійно та гарантує,
 * що пам'ять буде видалена, коли унікальний покажчик виходить за область дії.
 *
 * @tparam T Тип об'єкта, на який вказує покажчик.
 */
template <typename T>
class UniquePtr {
private:
    T* ptr; ///< Вказівник на об'єкт.

public:
    /**
     * @brief Конструктор класу UniquePtr.
     *
     * Ініціалізує об'єкт UniquePtr вказівником на переданий об'єкт.
     *
     * @param p Вказівник на об'єкт, який власник буде володіти.
     */
    UniquePtr(T* p) : ptr(p) {}

    /**
     * @brief Деструктор класу UniquePtr.
     *
     * Видаляє пам'ять, на яку вказує внутрішній вказівник.
     */
    ~UniquePtr() {
        delete ptr;
    }

    /**
     * @brief Отримати внутрішній вказівник.
     *
     * @return Внутрішній вказівник на об'єкт.
     */
    T* get() const {
        return ptr;
    }

    /**
     * @brief Перевантаження оператора розіменування.
     *
     * @return Звернення до об'єкту, на який вказує внутрішній вказівник.
     */
    T& operator*() const {
        return *ptr;
    }

    /**
     * @brief Перевантаження оператора стрілки.
     *
     * @return Вказівник на об'єкт.
     */
    T* operator->() const {
        return ptr;
    }

    // Заборона копіювання та присвоєння
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
};

/**
 * @brief Клас розумного покажчика, який імітує функціональність shared_ptr в C++.
 *
 * SharedPtr дозволяє кільком власникам використовувати один ресурс та гарантує,
 * що пам'ять буде видалена тільки після останнього використання.
 *
 * @tparam T Тип об'єкта, на який вказує покажчик.
 */
template <typename T>
class SharedPtr {
private:
    T* ptr; ///< Вказівник на об'єкт.
    int* refCount; ///< Вказівник на лічильник посилань.

public:
    /**
     * @brief Конструктор класу SharedPtr.
     *
     * Ініціалізує об'єкт SharedPtr вказівником на переданий об'єкт.
     * Лічильник посилань ініціалізується значенням 1.
     *
     * @param p Вказівник на об'єкт, який буде власником.
     */
    SharedPtr(T* p) : ptr(p), refCount(new int(1)) {}

    /**
     * @brief Конструктор копіювання класу SharedPtr.
     *
     * Збільшує лічильник посилань та копіює вказівник на об'єкт.
     *
     * @param other Інший SharedPtr, з якого копіюється вказівник та лічильник.
     */
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        (*refCount)++;
    }

    /**
     * @brief Деструктор класу SharedPtr.
     *
     * Зменшує лічильник посилань та видаляє пам'ять, якщо лічильник стає нульовим.
     */
    ~SharedPtr() {
        (*refCount)--;
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
        }
    }

    /**
     * @brief Перевантаження оператора присвоєння для класу SharedPtr.
     *
     * @param other Інший SharedPtr, з якого копіюється вказівник та лічильник.
     * @return SharedPtr з копією вказівника та лічильника.
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
     * @brief Отримати внутрішній вказівник.
     *
     * @return Внутрішній вказівник на об'єкт.
     */
    T* get() const {
        return ptr;
    }

    /**
     * @brief Перевантаження оператора розіменування.
     *
     * @return Звернення до об'єкту, на який вказує внутрішній вказівник.
     */
    T& operator*() const {
        return *ptr;
    }

    /**
     * @brief Перевантаження оператора стрілки.
     *
     * @return Вказівник на об'єкт.
     */
    T* operator->() const {
        return ptr;
    }

    /**
     * @brief Отримати кількість власників об'єкта.
     *
     * @return Лічильник посилань - кількість власників об'єкта.
     */
    int useCount() const {
        return *refCount;
    }
};

#endif // SMART_POINTER_H
