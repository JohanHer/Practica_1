#include <iostream>

using namespace std;

int main()
{
    short opcion = -1, digit;
    long int a,b, rev, temp, temp2, i, j, count, aux;
    char c;

    while(opcion!=0)
    {
     cout <<"Menu practica 1"<<endl;
     cout <<"1. Problema 2"<<endl;
     cout <<"2. Problema 3"<<endl;
     cout <<"3. Problema 5"<<endl;
     cout <<"4. Problema 7"<<endl;
     cout <<"5. Problema 9"<<endl;
     cout <<"6. Problema 10"<<endl;
     cout <<"7. Problema 11"<<endl;
     cout <<"8. Problema 13"<<endl;
     cout <<"9. Problema 14"<<endl;
     cout <<"10. Problema 16"<<endl;
     cout <<"0. para salir"<<endl;
     cin>>opcion;

    switch (opcion) {
        default:
            cout<<"Este problema no fue asignado"<<endl;
            break;

        case 1: //Problema 2
            cout<<"Ingrese la cantidad de dinero: ";cin>>a;
            if(a>=0){
                cout<<"50000: "<<a/50000<<endl; a %= 50000;
                cout<<"20000: "<<a/20000<<endl; a %=20000;
                cout<<"10000: "<<a/10000<<endl; a %= 10000;
                cout<<"5000: "<<a/5000<<endl; a %= 5000;
                cout<<"2000: "<<a/2000<<endl; a %= 2000;
                cout<<"1000: "<<a/1000<<endl; a %= 1000;
                cout<<"500: "<<a/500<<endl; a %= 500;
                cout<<"200: "<<a/200<<endl; a %= 200;
                cout<<"100: "<<a/100<<endl; a %= 100;
                cout<<"50: "<<a/50<<endl; a %= 50;
                cout<<"Faltante: "<<a<<endl;
            }
            else cout<<"Recuerde que el dinero siempre es positivo"<<endl;
            break;

        case 2: //Problema 3
            a=0;
            while(a != -1){
                cout<<"Ingrese el numero de mes (-1 para salir): "; cin>>a;
                if (a>=1 && a<=12){
                    cout<<"Ingrese el numero de dia: "; cin>>b;
                    if (b>=1 && b<=31){
                        cout<<"\n"<<a<<'/'<<b;
                        if (a==4 || a==6 || a==9 || a==11){ //meses de 30 dias
                            if(b==31) cout<<"Esta es una fecha invalida\n"<<endl;
                            else cout<<"Esta es una fecha valida\n"<<endl;
                        }
                        else if (a==2){ //febrero
                            if (b == 29) cout<<"Esta es una fecha valida de año bisiesto\n"<<endl;
                            else if (b<=28) cout<<"Esta es una fecha valida\n"<<endl;
                            else cout<<"Esta es una fecha invalida\n"<<endl;
                        }
                        else{ //meses de 31 dias
                            cout<<"Esta es una fecha valida\n"<<endl;
                        }
                    }
                    else cout<<b<<"Este es un dia invalido.\n"<<endl;
                }
                else if (a == -1) cout<<"Has salido correctamente\n"<<endl;
                else cout<<a<<"Este es un mes invalido.\n"<<endl;
            }
            break;

        case 3: //Problema 5
            cout<<"Ingrese el numero de filas: "; cin>>digit; //a = filas, b = columnas
            if(digit>0){
                if (digit%2 != 0){ //Verifica que es impar
                    digit--;
                    temp = digit/2; //"Cantidad de espacios"
                    for(int k = 1, a=0; a >= 0; a += k ){ //Recorre las filas
                            if (a>=(digit/2)) k = -1; //Revierte el avance del ciclo
                            for(b = 0; b <= digit; b++){ //Recorre las columnas
                                if(b<temp || b>digit-temp) cout << ' ';
                                else if (b>=temp) cout << '*';
                            }
                            if (k==1) temp--; //Reduce la cantidad de espacios hasta que llega a la mitad
                            else temp++; //Aumenta la cantidad de espacios despues de la mitad
                            cout<<endl;
                        }
                    }
                    else cout<<"Recuerda que el numero de filas debe ser impar"<<endl;
                }
            else cout<<"Recuerde que el numero de filas debe ser positivo"<<endl;
            break;

        case 4: //Problema 7
            //se usa un for para definir las variables grandes, ya que al terminar la ejecucion estas se eliminan automaticamente.
            for( long long unsigned int term1, term2, large_count, large_sum, large_digit, large_temp; true; ){
                cout<<"Ingrese la cantidad de terminos de la serie : "; cin>>large_digit;
                if (large_digit <= 1134903171 && large_digit>0){ //Si se ingresa un valor mayor puede salir negativo gracias a que se sale del rango de la variable
                    term1=1; term2=1;
                    large_sum=0;
                    for(large_count=0; large_count<large_digit-2; large_count++){ //calcula la serie de Fibonacci
                        large_temp = term1+term2;
                        term1 = term2;
                        term2 = large_temp;
                        if(large_temp%2 == 0 && large_temp<large_digit && large_temp>0) large_sum += large_temp;
                    }
                    cout<<"El resultado de la suma es: "<<large_sum<<endl;
                    break;
                }
                else if (large_digit >= 1134903171) {
                    cout<<"La suma no es correcta debido a que el tamaño de los numeros de la serie excede el tamaño de los long unsigned int"<<endl;
                    break;
                }
                else {
                    cout<<"Recuerde que debe ingresar un numero positivo"<<endl;
                    break;
                }
            }
            break;

        case 5: //Problema 9
            rev=0;
            temp = 1;
            cout<<"Ingrese un numero: "; cin>>a;
            if(a<0) a *= -1; //Si es negativo lo vuelve positivo
                for(; a>0; (a /= 10)&&(temp = 1)){ //en cada ciclo le quita un digito a 'a' y hace reset a temp
                   digit = (a%10); //captura un digito de a
                   for(temp2 = digit ; temp2>0; --temp2){ // calcula la potencia en temp
                        temp *= digit;
                    }
                    rev += temp; //suma temp al total
                }
                cout<<"\nLa suma de la potencias de sus digitos es: "<<rev<<endl;
            break;

        case 6: //Problema 10
            cout<<"Ingrese el primo n que desea ver: ";cin>>a;
            if(a>0){
                temp = 1;
                aux = 1;
                for(count=0; count<a; ){ //cuenta  entre  1 y a
                    aux++; //Potencial numero primo
                    for(rev=2; rev<=(aux/2); rev++){ //verifica si es primo
                        if(aux%rev==0) {// si es divisible por algun numero rompe el ciclo
                            temp = 0;
                            break;
                        }
                        else if(aux%rev != 0){
                            temp = 1;
                        }
                    }
                    if(temp != 0) count++; //si es un primo suma al contador
                }
                cout<<"\nEl primo numero "<<a<<" es: "<<aux<<endl;
            }
            else cout<<"Recuerde ingresar una posicion valida"<<endl;
            break;

        case 7: //Problema 11
            cout<<"Ingrese el numero: "; cin>>a;
            if (a>0){
                b = 1;
                rev = 1;
                cout<<"El MCM de todos los numero menores a "<<a<<" es: ";
                for(; a>0; a--){
                    temp = a;
                    temp2 = b;
                    while(temp != temp2) { //Calcula el MCD entre a y b
                        if(temp > temp2)
                            temp -= temp2;
                        else
                            temp2 -= temp;
                    }
                    b = (a*b)/temp; //Formula para el MCM: (a*b)/MCD(a, b)
                }
                cout<<b<<endl;
            }
            else cout<<"Recuerde ingresar un entero positivo"<<endl;
            break;

        case 8: //Problema 13
            cout<<"Ingrese el numero: ";cin>>a;
            if(a>0){
                temp = 1;
                aux = 2;
                temp2=0;
                for(; aux<a; aux++){ //cuenta  entre  1 y a
                    for(rev=2; rev<=(aux/2); rev++){ //verifica si es primo
                        if(aux%rev==0) {//Si es divisible por algun numero detiene el ciclo
                            temp = 0;
                            break;
                        }
                        else if(aux%rev != 0){
                            temp = 1;
                        }
                    }
                    if(temp != 0) {
                        count++;
                        temp2+=aux;
                    }
                }
                cout<<"\nLa suma de los primos menores a "<<a<<" es: "<<temp2<<endl;
            }
            else cout<<"Recuerde ingresar un numero positivo"<<endl;
            break;

        case 9: //Problema 14
            cout<<"Si quiere ver todos los palindromos ingrese 'y', de lo contrario ingrese 'n': ";cin>>c;
            /*
            Fuerza bruta no es la mejor opciòn en cuanto a eficiencia(~406.000 iteraciones), pero no pude encontrar ninguna documentacion
            sobre metodos para calcular numeros palindromos como multiplicacion de numeros de 3 cifras.
            */
            a = 999;
            b = 999;
            temp2 = 0;
            count = 0;
            while(a>99 && b>99){ //no se usan numeros con menos de 3 cifras
                for(; b>99; b--){
                    temp = a*b;
                    aux = temp;
                    rev=0;
                    while(temp>0){ //verifica si es palindromo
                        digit = temp % 10;
                        rev = (rev * 10) + digit;
                        temp = temp / 10;
                    }
                    if (aux == rev || aux==1 || aux==0) {
                        if(c=='y') cout <<a<<'*'<<b<<" = "<<aux<<endl;
                        if(aux>temp2) { //si el palindromo es mayor al anterior este se guarda junto con los numeros que lo generan
                                temp2=aux;
                                i =a; j = b;
                        }
                    }
                }
                b = a;
                a--;
            }
            cout<<"\nEl palindromo mas grande como multiplicacion de numeros de 3 cifras es: "<<temp2<<" = "<<i<<'*'<<j<<endl;
            break;

        case 10: //Problema 16
            cout<<"Ingrese un numero: "; cin>>a;
            if(a>0){
                cout<<"si quiere ver todas las series ingrese 't', si solo quiere ver la mas larga ingrese 'm', y si no quiere ver ninguna ingrese 'n': "; cin>>c;
                count = 0;
                temp = 0;
                for(; a>0; a--){ //prueba con todas las semillas menores a 'a'
                    b = a;
                    while(true){ //se calcula la serie
                        if(c=='t') cout<<b<<' ';
                        count++;
                        if(b%2 == 0) b /= 2;
                        else b = (3*b)+1;
                        if (b==1) {
                            count++;
                            if(c=='t') cout<<'1'<<endl;
                            break;
                        }
                    }
                    if(temp<count) { //si la serie tiene mas terminos que la anterior se guarda la semilla y la cantidad de terminos
                        temp = count;
                        temp2 = a;
                    }
                    count = 0;
                }
                if(c == 'n' || c == 't') cout<<"La serie mas larga es con la semilla "<<temp2<<" y tiene "<<temp<<" terminos"<<endl;
                if(c == 'm'){ //imprime la serie mas larga
                    a = temp2;
                    b = a;
                    while(true){
                        cout<<b<<' ';
                        count++;
                        if(b%2 == 0) b /= 2;
                        else b = (3*b)+1;
                        if (b==1) {
                            count++;
                            cout<<'1'<<endl;
                            break;
                        }
                    }
                    cout<<"La serie mas larga es con la semilla "<<temp2<<" y tiene "<<temp<<" terminos"<<endl;
                }
            }
            else cout<<"Ingrese una entrada valida!"<<endl;
            break;

        }
    }
    return 0;
}
