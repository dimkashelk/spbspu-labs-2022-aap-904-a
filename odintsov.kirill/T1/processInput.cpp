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
    } else if (command == "COMPLEXQUAD") {
      composite.push_back(readComplexQuad(in));
    } else if (command == "RECTANGLE") {
      composite.push_back(readRectangle(in));
    } else if (command == "SCALE") {
      point_t anchor = readPoint(in);
      double k = 1.0;
      in >> k;
      if (!in) {
        throw std::runtime_error("input error");
      }
      if (k < 0.0) {
        throw std::invalid_argument("coefficient should be positive");
      }
      odintsov::outputCompositeShape(out, composite) << '\n';
      for (size_t i = 0; i < composite.size(); i++) {
        isoScale(composite[i], anchor, k);
      }
      odintsov::outputCompositeShape(out, composite) << '\n';
    } else {
      out << "Not a known command\n";
    }
  } catch (const std::exception& err) {
    out << "Non-fatal error: " << err.what() << '\n';
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
