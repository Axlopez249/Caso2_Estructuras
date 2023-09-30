#include "json.hpp"

struct ConfigSimulacion
{
    string "Unidad";
    float RelacionReal;
    int ventanillas;
}

class ConfigJson
{
private:
    ConfigSimulacion currentConfigSimulacion;
    List<string> *refrescos;
    List<string> *comidas;
    List<string> *postres;

    void parseAllJson()
    {
        // cargar todo en estructuras
    }

public:
    ConfigJson()
    {
        // cargar el json al objecto
        // inicializo las listas
        parseAllJson();
    }

    ConfigSimulacion getConfigSimulacion()
    {
        return currentConfigSimulacion;
    }

    List<string> *getRefrescos()
    {
        return refrescos;
    }

    int getMinTiempoFilaVentanilla()
    {
    }

    int getMaxTiempoFilaVentanilla()
    {
    }

    //.. and so on
}