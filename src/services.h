#pragma once

#include <string>
#include <json.hpp>
#include "consoleUtils.h"
#include "services.h"

using json = nlohmann::json;

namespace gnu {

// La URL de la API donde anticine obtiene sus datos
// Repositorio: https://github.com/GNUfamilia-fisi/anticine-server
std::string apiURL = "https://api.anticine.up.railway.app";

/**
 * Hace una petición a una URL y devuelve su respuesta.
 * 
 * Por defecto solo funciona con JSONs, por ejemplo,
 * un `fetch("www.google.com")` terminaría en error, pues
 * Google te devuelve una página web en formato HTML,
 * no texto en formato JSON.
 * 
 * Por detrás, esta función usa gnu::exec() para ejecutar
 * el comando "curl", que sirve para hacer peticiones HTTP.
 * 
 * @example
 * json response = gnu::fetch("https://api.cinext.up.railway.app/cines/cercanos")
 */
json fetch(std::string url) {
    std::string command = "curl -s " + url;
    std::string fetchResult = gnu::exec(command);
    json data;

    try {
        data = json::parse(fetchResult);
    }
    catch (...) {
        throw std::runtime_error("Error al intentar hacer fetch a " + url);
    }
    return data;
}

/**
 * Usa a "fetch" con la url de nuestra API como base
 * 
 * Por ejemplo, el siguiente código:
 * json response = apifetch("/cines/cercanos")
 * 
 * Es equivalente a:
 * json response = fetch(apiURL + "/cines/cercanos")
 */
json apifetch(std::string ednpoint) {
    return fetch(apiURL + ednpoint);
}

} // namespace gnu
