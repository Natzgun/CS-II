#include <iostream>
#include <memory>

int main () {
  auto sptr = std::make_shared<int>(42);
  std::cout << "Initial count: " << sptr.use_count() << std::endl;
  std::weak_ptr<int> wk;
  wk = sptr;

  std::weak_ptr<int> wk2;
  wk2 = wk; 
  std::cout << "After count: " << sptr.use_count() << std::endl;
  
  auto shared2 = std::make_shared<int>();
  if (!wk2.expired()) {
    std::cout << "Weak ptr is not empty" << std::endl;
    shared2 = wk2.lock();
  } else { 
    std::cout << "Weak ptr is empty" << std::endl;
  }

  std::cout << "Finally count: " << sptr.use_count() << std::endl;

  /* weakIsEmpty(wk2);
  sptr.reset();
  weakIsEmpty(wk2); */
  return 0;
}
