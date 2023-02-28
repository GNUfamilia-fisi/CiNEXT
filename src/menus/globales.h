#pragma once

#include <string>
#include <vector>
#include <json.hpp>
#include "../consoleUtils.h"

using json = nlohmann::json;

// Variables globales compartidas por todos los menús
// (en un futuro intentaremos hacerlo más elegante, por ahora funciona)

std::string g_fechaSeleccionada; // (no usada)
std::string g_cineID;
std::string g_movieID;
std::string g_selectedDate = "";
std::string g_sessionID = "62254"; // testing
std::vector<gnu::vec2d> g_selectedSeats;
