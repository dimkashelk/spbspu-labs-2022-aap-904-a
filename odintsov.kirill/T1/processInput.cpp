#include "processInput.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "compositeshape.hpp"
#include "concave.hpp"
#include "complexquad.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

odintsov::point_t readPoint(std::istream& in)
{
  double x = 0.0;
  double y = 0.0;
  in >> x >> y;
  if (!in) {
    throw std::runtime_error("input error");
  }
  return odintsov::point_t{x, y};
}

odintsov::Rectangle* readRectangle(std::istream& in)
{
  odintsov::point_t p1 = readPoint(in);
  odintsov::point_t p2 = readPoint(in);
  return new odintsov::Rectangle(p1, p2);
}

odintsov::ComplexQuad* readComplexQuad(std::istream& in)
{
  odintsov::point_t p1 = readPoint(in);
  odintsov::point_t p2 = readPoint(in);
  odintsov::point_t p3 = readPoint(in);
  odintsov::point_t p4 = readPoint(in);
  return new odintsov::ComplexQuad(p1, p2, p3, p4);
}

odintsov::Concave* readConcave(std::istream& in)
{
  odintsov::point_t p1 = readPoint(in);
  odintsov::point_t p2 = readPoint(in);
  odintsov::point_t p3 = readPoint(in);
  odintsov::point_t p4 = readPoint(in);
  return new odintsov::Concave(p1, p2, p3, p4);
}

std::istream& odintsov::processCommand(std::istream& in, std::ostream& out, CompositeShape& composite)
{
  std::string command = "";
  in >> command;
  try {
    if (command == "CONCAVE") {
      composite.push_back(readConcave(in));
      return in;
    } else if (command == "COMPLEXQUAD") {
      composite.push_back(readComplexQuad(in));
      return in;
    } else if (command == "RECTANGLE") {
      composite.push_back(readRectangle(in));
      return in;
    }
  } catch (const std::exception& err) {
    std::cerr << "Non-fatal error: " << err.what() << '\n';
    return in;
  }
  if (command == "SCALE") {
    point_t anchor = readPoint(in);
    double k = 1.0;
    in >> k;
    if (!in) {
      throw std::runtime_error("input error");
    }
    if (k <= 0.0) {
      throw std::invalid_argument("coefficient should be positive");
    }
    if (composite.size() == 0) {
      throw std::logic_error("no shapes to scale");
    }
    odintsov::outputCompositeShape(out, composite) << '\n';
    for (size_t i = 0; i < composite.size(); i++) {
      isoScale(composite[i], anchor, k);
    }
    odintsov::outputCompositeShape(out, composite) << '\n';
  } else {
    out << "Not a known command\n";
  }
  return in;
}

std::istream& odintsov::processInput(std::istream& in, std::ostream& out, CompositeShape& composite)
{
  do {
    std::string commandLine = "";
    std::getline(in, commandLine);
    if (in.eof()) {
      break;
    }
    if (commandLine == "") {
      continue;
    }
    std::istringstream iss(commandLine);
    processCommand(iss, out, composite);
  } while (!in.eof());
  return in;
}
