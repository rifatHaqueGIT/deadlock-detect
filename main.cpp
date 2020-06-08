#include <iostream>
#include <tuple>
#include <string>

class Deadlock {
 public:
  std::tuple<bool,std::string>
  lock( std::string process, std::string resource);
};

int main()
{
  Deadlock dlock;
  bool res;
  std::string msg;
  std::tie(res, msg) = dlock.lock("dude", "7");

  std::cout << res << "," << msg << "\n";
}


std::tuple<bool,std::string>
Deadlock::lock( std::string process, std::string resource)
{
  return { false, "Bad boy" };
}
