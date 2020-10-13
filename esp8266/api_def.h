// ACE2 2S 2020
// Leonel Aguilar

#ifndef API_DEF
#define API_DEF

// En este archivo se deben escribir todas
// las funciones con cada ruta que se consumira de la API

// Definir la cantidad de rutas y funciones a registrar
const int routeCount = 1;
String state_str = "inactivo";

String routes[1] = {
  "state"
};

void sendStatusRequest() {
  debug("Realizando petición [sendStatus]");

  String state_str = app_request(routes[0]);
  state_str.trim();
  
  if ( state_str == "activo" ) {
    state_from_server = 1;
  } 
  else {
    state_from_server = 0;
  }
}

// Definir como un par ordenad todas las funciones
// que haran las rutas previamente definidas en el arreglo "routes"
// cada vez que se haga match con un valor del arreglo se llamara a
// la funcion contenida en este arreglo en el mismo indice
// donde se encontro la ruta
void (*functions[routeCount]) () = {
  sendStatusRequest
};

// Procesar una llamada hacia la API
void process_api_request(int route) {
  debug(String("Encontrando la ruta: ") + route);
  // comparar con cada elemento del arreglo de nombres de rutas
  if (route >= routeCount) {
    debug("Error crítico: ruta " + String(routeCount) + " no encontrada");
  } else {
    debug(String("Ruta identificada ruta almacenada: ") + routes[route]);
    debug("Llamando a la funcion emparejada de la ruta");
    (*functions[route])();
  }
}

#endif
