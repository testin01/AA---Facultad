using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

void inicializarVector(int vector[], int cantPos, int valorInit)
{
    for (int i = 0; i < cantPos; i++)
    {
        vector[i] = valorInit;
    }
}

void mostrarVector(int vector[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "El valor de v[" << i << "] es: " << vector[i] << endl;
    }
}

void cargaMasiva(int vec[], int &len, int cantPos)
{
    for (int i = 0; i < cantPos; i++)
    {
        cout << "Ingresar un valor: " << endl;
        cin >> vec[i];
        len++;
    }
}

void insertar(int vec[], int &len, int valor, int pos)
{
    for (int i = len; i > pos; i--)
    {
        vec[i] = vec[i - 1];
    }
    vec[pos] = valor;
    len++;
}

void insertarOrdenado(int vec[], int &len, int valor)
{
    // Definir donde se inserta
    int i = 0;
    while (i < len && vec[i] <= valor)
    {
        i++;
    }

    // Hacer la insercion
    if (i == len)
    {
        vec[len] = valor;
    }
    else
        insertar(vec, len, valor, i);
}

int buscar(int vec[], int len, int valor)
{
    int ret = -1;
    int i = 0;
    while (i < len && vec[i] != valor)
    {
        i++;
    }
    if (i != len)
    {
        ret = i;
    }

    return ret;
}

void eliminar(int vec[], int &len, int pos)
{
    for (int i = pos; i < len - 1; i++)
    {
        vec[i] = vec[i + 1];
    }
    len--;
}

/**********************PILAS********************************/
void push(Nodo *&pila, int valor)
{
    // cargar nodo
    Nodo *p = new Nodo(); // Pedido de memoria
    p->info = valor;      // cargamos en el nodo el valorr que me pasaron
    p->sgte = pila;       // apunta al ultimo

    // enlazar el nodo
    pila = p;
}

// eliminar nodo
int pop(Nodo *&pila)
{
    int ret = pila->info; // asegurás el retorno
    // eliminar el nodo
    Nodo *aux = pila;
    pila = pila->sgte; // pila = aux->sgte;
    delete (aux);
    // acomodar puntero
    return ret;
}

/**********************COLAS******************************/
void agregar(Nodo *&cfte, Nodo *&cfin, int valor)
{
    // Cargar el nodo y cargarlo
    Nodo *nuevo = new Nodo(); // Pedido de memoria para el nodo
    nuevo->info = valor;
    nuevo->sgte = NULL;

    // Enlazo en la estructura
    if (cfte == NULL) // significa que la cola está vacia
    {
        cfte = nuevo;
    }
    else
    {
        cfin->sgte = nuevo;
    }
    cfin = nuevo;
}

int suprimir(Nodo *&cfte, Nodo *&cfin)
{
    // aseguro el retorno
    int ret = cfte->info;
    // liberar la memoria usada para el nodo eliminado y actualizar el o los punteros
    Nodo *aux = cfte;
    cfte = cfte->sgte;
    if (cfte == NULL) // escenario anómalo
    {
        cfin = NULL; // actualizo solamente porque se acabó la cola
    }
    delete (aux);
    return ret;
}

/*********************LISTAS******************************/

void agregarPrimero(Nodo *&Lista, int valor)
{
    // Crear el nodo y cargarlo
    Nodo *nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = NULL;

    // enlazar la lista
    if (Lista != NULL) // Lista cargada
    {
        nuevo->sgte = Lista;
    }
    Lista = nuevo; // Lista vacia
}

void agregarNodo(Nodo *&Lista, int valor)
{
    // Crear el nodo y cargarlo
    Nodo *nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = NULL;

    // enlace
    if (Lista == NULL)
    {
        Lista = nuevo;
    }
    else // Recorro hasta encontrar el final de la lista
    {
        Nodo *aux = Lista;
        while (aux->sgte != NULL)
        {
            aux = aux->sgte;
        } // Ya tengo el último NODO
        aux->sgte = nuevo;
    }
}

void mostrar(Nodo *Lista)
{
    Nodo *aux = Lista;
    while (aux != NULL)
    {
        cout << "El valor de la lista es " << aux->info << endl;
        aux = aux->sgte;
    }
}

void liberar(Nodo *&Lista)
{
    Nodo *aux;
    while (Lista != NULL)
    {
        aux = Lista;
        Lista = Lista->sgte;
        delete (aux);
    }
}

Nodo *buscar(Nodo *Lista, int valor)
{
    Nodo *aux = Lista;
    while (aux != NULL && valor != aux->info)
    {
        aux = aux->sgte;
    }
    return aux;
}

int eliminarPrimerNodo(Nodo *&Lista)
{
    // Asegurar retorno
    int ret = Lista->info;
    // Liberar memoria y dejar lista enlazada
    Nodo *aux = Lista;
    Lista = Lista->sgte;
    delete (aux);

    return ret;
}

void insertarOrdenado(Nodo *&Lista, int valor)
{
    // Crear el nodo y cargarlo
    Nodo *nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = NULL;

    // Enlazarlo (encontrar el lugar donde debo insertarlo)
    Nodo *nodoAnterior = NULL;
    Nodo *aux = Lista;

    while (aux != NULL && aux->info < valor)
    {
        nodoAnterior = aux;
        aux = aux->sgte;
    }

    if (nodoAnterior == NULL)
    {
        Lista = nuevo;
    }
    else
    {
        nodoAnterior->sgte = nuevo;
    }
    nuevo->sgte = aux;
}