
#ifndef CRAWLER_HPP_
#define CRAWLER_HPP_

// boost
#include "common.hpp"

class crawler {
 public:
  crawler(const console_commands&);

 private:
  console_commands __commands{};
};

#endif  // CRAWLER_HPP_
