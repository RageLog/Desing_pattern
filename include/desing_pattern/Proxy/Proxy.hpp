#pragma once
#include <iostream>
#include <memory>

namespace virtualProxy
{
class absObject
{
 private:
 public:
  absObject();
  virtual void doSomeThing() = 0;
  virtual ~absObject() = 0;
};

class Object : public absObject
{
 private:
 public:
  Object();
  ~Object();
  void doSomeThing() override;
};

// ! in this case you can override the -> operator for different access to object
class Proxy : public absObject
{
 private:
  std::unique_ptr<Object> m_object{nullptr};
  void doSomePrivateChecksAndLogOrOtherThings() const;  // ! Don't name it like that.
 public:
  Proxy();
  ~Proxy();
  void doSomeThing() override;
};

}  // namespace virtualProxy

namespace propertyProxy
{
template <typename T>
class Property
{
 private:
  T m_value;

 public:
  Property(const T& value)
  {
    *this = value;
  }
  operator T()
  {
    return m_value;
  }
  T operator=(const T& rhs)
  {
    std::cout << "Value change with " << rhs << '\n';
    return m_value = rhs;
  }
};

struct someObject
{
  Property<uint16_t> value_1{0};
  Property<uint16_t> value_2{0};
};

}  // namespace propertyProxy

// ! According to Vishal Chovatiya, This is communication proxy
// ! Hi's say that: [] operator overload is most common usage of this proxy type in C++
// ! I can't derivate this exemple for common usage :/
/*
    template <typename T>
    struct arr2D {
        struct proxy {
            proxy(T *arr) : m_arr_1D(arr) {}
            T &operator[](int32_t idx) {
                return m_arr_1D[idx];
            }
            T   *m_arr_1D;
        };
        arr2D::proxy operator[](int32_t idx) {
            return arr2D::proxy(m_arr_2D[idx]);
        }
        T   m_arr_2D[10][10];
    };
    int main() {
        arr2D<int32_t> arr;
        arr[0][0] = 1;  // Uses the proxy object
        return EXIT_SUCCESS;
    }
*/