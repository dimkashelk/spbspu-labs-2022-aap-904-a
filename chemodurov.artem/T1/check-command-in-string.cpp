#include "check-command-in-string.hpp"

bool chemodurov::checkCommand(const std::string & line, const char * command)
{
  size_t command_size = 0;
  for (const char * i = command; *i != '\0'; ++i)
  {
    command_size++;
  }
  return (!line.compare(0, command_size, command));
}
