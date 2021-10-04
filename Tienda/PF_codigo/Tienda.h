#include <vector>

class Productos{
  private:
    string producto;
    double precioUnitario;
    int num;

  public:
    Productos(int num, string producto, double precioUnitario){
      this -> num = num;
      this -> producto = producto;
      this -> precioUnitario = precioUnitario;
    }

    string getProducto(){
      return producto;
    }

    double getPrecioUnitario(){
      return precioUnitario;
    }

    int getNum(){
      return num;
    }
};

class PlantasInteriores : public Productos{
  private:
    char size;
    string color, luminosidad, riego;
  public:
		// Categoría 1. (0-9)
		// | #  | Nombre   | Precio  | Color    | Tamaño  |
    PlantasInteriores(int num, string producto, double precioUnitario, string color, char size) : Productos(num, producto, precioUnitario){
      this -> color = color;
      this -> size = size;
    }

		// Categoría 2. (10-16)
		// | #  | Nombre   | Precio  | Luminosidad  | Riego  |
    PlantasInteriores(int num, string producto, double precioUnitario, string luminosidad, string riego) : Productos(num, producto, precioUnitario){
      this -> luminosidad = luminosidad;
      this -> riego = riego;
    }

		// Categoría 3. (17-24)
		// | #  | Nombre   | Precio  | Tamaño  |
    PlantasInteriores(int num, string producto, double precioUnitario, char size) : Productos(num, producto, precioUnitario){
      this -> size = size;
    }

    string getColor(){
      return color;
    }

    char getSize(){
      return size;
    }

    string getLuminosidad(){
      return luminosidad;
    }

    string getRiego(){
      return riego;
    }
};

class SeleccionarProductos{
  private:
    PlantasInteriores * florales[25];
    int producto, unidades;
    float suma, sumados, importe;
    vector < PlantasInteriores * > comprados;
    vector < int > uni;
    vector < float > imp;
  
  public: 
    SeleccionarProductos(){
			// Categoría 1. 
			// | #  | Nombre   | Precio  | Color    | Tamaño  |
      florales[0] = new PlantasInteriores(1,"Margarita", 78.28, "Violeta", 'G');
      florales[1] = new PlantasInteriores(2,"Begonia", 50.45, "Naranja", 'S');
      florales[2] = new PlantasInteriores(3,"Azalea", 67.34, "naranja", 'M');
      florales[3] = new PlantasInteriores(4,"Gardenia", 62.08, "Amarilla", 'M');
      florales[4] = new PlantasInteriores(5,"Celosia", 20.76, "Rosa", 'S');
      florales[5] = new PlantasInteriores(6,"Rosal", 80.54, "Rojo", 'G');
      florales[6] = new PlantasInteriores(7,"Margarita", 40.32, "Azul", 'S');
      florales[7] = new PlantasInteriores(8,"Gardenia", 31.45, "Blanca", 'S');
      florales[8] = new PlantasInteriores(9,"Begonia", 70.32, "Rosa", 'G');
      florales[9] = new PlantasInteriores(10,"Azalea", 30.56, "Azel", 'S');
			
			// Categoría 2.
			// | #  | Nombre   | Precio  | Luminosidad  | Riego  |
      florales[10] = new PlantasInteriores(11,"Zamioculca", 47.56, "Baja", "Alto");
      florales[11] = new PlantasInteriores(12,"Helecho", 63.87, "Medio", "Bajo");
      florales[12] = new PlantasInteriores(13,"Carnivora", 32.89, "Media", "Bajo");
      florales[13] = new PlantasInteriores(14,"Pilea", 98.67, "Bajo", "Bajo");
      florales[14] = new PlantasInteriores(15,"Dracena", 47.89, "Alto", "Medio");
      florales[15] = new PlantasInteriores(16,"Monstera", 20.67, "Medio", "Alto");
      florales[16] = new PlantasInteriores(17,"Pilea", 40.78, "Alto", "Alto");
			
			// Categoría 3.
			// | #  | Nombre   | Precio  | Tamaño  |
      florales[17] = new PlantasInteriores(18, "Suculenta", 40.87, 'M');
      florales[18] = new PlantasInteriores(19, "Suculenta", 12.65, 'S');
      florales[19] = new PlantasInteriores(20,"Sedum", 42.76, 'M');
      florales[20] = new PlantasInteriores(21,"Aloe", 64.21, 'G');
      florales[21] = new PlantasInteriores(22,"Sanseveira", 50.43, 'M');
      florales[22] = new PlantasInteriores(23,"Suculenta", 60.17, 'G');
      florales[23] = new PlantasInteriores(24,"Sedum", 20.87, 'S');
      florales[24] = new PlantasInteriores(25,"Sanseveira", 30.45, 'S');
    } 

    SeleccionarProductos(PlantasInteriores * florales[]){
      SeleccionarProductos productos = SeleccionarProductos(florales);
      for(int i = 0; i < 25; i++){
        this -> florales[i] = florales[i];
      }
    }

    void imprimir(){
      cout << "Producto" << "         " << "Descripción" << "                  " << "Precio" << endl;
      for (int i = 0; i < 9; i++){
        cout << florales[i] -> getNum() << ") " << florales[i] -> getProducto() << "     " << "Color " << florales[i] -> getColor()<< ", tamaño " << florales[i] -> getSize()<< "      " << florales[i]-> getPrecioUnitario() << endl;
      }

      for (int i = 9; i < 16; i++){
        cout << florales[i] -> getNum()<< ") " << florales[i] -> getProducto() << "     " << "luminosidad " << florales[i] -> getLuminosidad() << ", riego " << florales[i] -> getRiego() << "      " << florales[i] -> getPrecioUnitario() << endl;
      }

      for (int i = 16; i < 25; i++){
        cout << florales[i] -> getNum() << ") "<<florales[i] -> getProducto() << "               " << "tamaño " << florales[i] -> getSize() << "                  " << florales[i] -> getPrecioUnitario() << endl;
      }

      cout << endl;
      cout << "¿Qué producto deseas comprar? (-1 para cancelar): ";
      cin >> producto;
    }

    void comprar(){
      if(producto != -1){
        cout << "¿Cuántas unidades deseas adquirir? (-1 para cancelar): ";
        cin >> unidades;
        uni.push_back(unidades);
        if(unidades != -1){
          cout << endl;
          importe = florales[producto-1]-> getPrecioUnitario() * unidades;
          imp.push_back(importe);
          cout << "––>" << unidades<< " unidades de " << florales[producto-1] -> getProducto() << " a $" << florales[producto-1] -> getPrecioUnitario() << " c/u" << ", IMPORTE: $" << importe << endl;
          comprados.push_back(florales[producto-1]);
          suma += importe;
          sumados += unidades;
          cout << endl;
        }else{
          cout << endl;
          cout << "––> Su elección ha sido CANCELADA" << endl;
          cout << endl;
        }
      }else{
        cout << endl;
        cout << "––> Su elección ha sido CANCELADA"<<endl;
        cout << endl;
      }
    }

    void carritoCompras(){
      cout << "Cantidad" << "  " << "Producto" << "   " << "P.Unitario" << "    " << "Importe" << endl;
      for(int i=0; i < comprados.size(); i++){
        cout << uni[i] << "         " << comprados[i] -> getProducto() << "   " << "$" << comprados[i] -> getPrecioUnitario() << "    " << "$" << imp[i] << endl;
      }
      cout << endl;
      cout << "_____________________________________________" << endl;
      cout << "                               TOTAL: " << suma << endl;
      cout << endl;
    }

    void finalizarCompra(){
      if(sumados > 10){
        cout << "¡Tienes una compra con más de 10 PRODUCTOS!" << endl;
        float num = (rand()%(20))+5;
        cout << "Por lo que tienes un descuento del: " << num << "%" << endl;
        cout << endl;
        float descuento = suma*(num/100);
        float destotal = suma-descuento;
        cout << "––> Total de tu compra original (sin descuento): " << suma << endl; 
        cout << "––> Total de tu compra con descuento: " << destotal << endl;
        cout << endl;
        cout << "––> ¡GRACIAS POR TU COMPRA! <––" << endl;
        cout << endl;
      }else{
        cout << "El total de tu compra es: " << suma << endl;
        cout << "––> ¡GRACIAS POR TU COMPRA! <––" << endl;
        cout << endl;
      }
    }
    
    int getProducto(){
      return producto;
    } 
};

class Menu : public SeleccionarProductos{
  private:
    int seleccion;

  public:
    void imprimeMenu(){
      cout << "*******************************" << endl;
      cout << "  Bienvenido a miplantita.com" << endl;
      cout << "*******************************" << endl;
      cout << "––> Sofía Donlucas A01655565 y Alexa Serrano A01654063" << endl;
      cout << endl;

      while(seleccion!=4){
        cout << "----------------" << endl;
        cout << " MENÚ PRINCIPAL" << endl;
        cout << "----------------" << endl;
        cout << "(1) Seleccionar producuctos." << endl;
        cout << "(2) Ver carrito de compras." << endl;
        cout << "(3) Terminar compra." << endl;
        cout << "(4) Salir." << endl;
        cout << "Selecciona opción: ";
        cin >> seleccion;

        while(seleccion==1){
          if(getSeleccion()==1){
              cout << endl;
              cout << "-----------------------" << endl;
              cout << "  PLANTAS DISPONIBLES" << endl;
              cout << "-----------------------" << endl;
              imprimir();
              comprar();
              cout << "----------------" << endl;
							cout << " MENÚ PRINCIPAL" << endl;
							cout << "----------------" << endl;
							cout << "(1) Seleccionar producuctos." << endl;
							cout << "(2) Ver carrito de compras." << endl;
							cout << "(3) Terminar compra." << endl;
							cout << "(4) Salir." << endl;
							cout << "Selecciona opción: ";
							cin >> seleccion;
          }

          while(getSeleccion()==2){
              cout<<endl;
              cout << "----------------------" << endl;
              cout << "  CARRITO DE COMPRAS" << endl;
              cout << "----------------------" << endl;
              carritoCompras();
              cout<<"----------------"<<endl;
              cout<<" MENU PRINCIPAL"<<endl;
              cout<<"----------------"<<endl;
              cout<<"1) Seleccionar producuctos"<<endl;
              cout<<"2) Ver carrito de compras"<<endl;
              cout<<"3) Terminar compra"<<endl;
              cout<<"4) Salir"<<endl;
              cout<<"Selecciona opcion: ";
              cin>>seleccion;
          }
        }

        if(getSeleccion()==2){
          cout<<endl;
					cout << "----------------------" << endl;
					cout << "  CARRITO DE COMPRAS" << endl;
					cout << "----------------------" << endl;
          cout << "¡Ups! El carrito de compras está vacío :(" << endl;
          cout << endl;
        }else if(getSeleccion()==3){
          cout << endl;
          cout << "-------------------" << endl;
          cout << "  TERMINAR COMPRA" << endl;
          cout << "-------------------" << endl;
          finalizarCompra();
        }
      }
      cout << endl;
      cout << "––> APLICACIÓN FINALIZADA <–– " <<endl;
    }

    int getSeleccion(){
      return seleccion;
    }
};