#include "pch.h"
#include<Windows.h>
#include "List.h"
#include "InfoPo.h"
#include <string>
#include "PokeGenComparator.h"
#include"PokeNatNumComparator.h"
using namespace System;
using std::string; 

void MarshalString(String^ s, string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

List<InfoPo>* readInfoPo(String^ filePath)
{
    List<InfoPo>* Poke = new List<InfoPo>(); 
    array<String^>^ lines = System::IO::File::ReadAllLines(filePath);
    for (int i=0; i<lines->Length; i++)
    {
        array<String^>^ line = lines[i]->Split(','); 

        string name; 
        int NatNum = int::Parse(line[0]);
        MarshalString(line[1], name); 
        int generacion = int::Parse(line[2]); 
        InfoPo* poke = new InfoPo(i, NatNum,  name, generacion); 

        Poke->add(poke); 
    }

    return Poke; 
}

void showPoke(List<InfoPo>* pokede)
{
    Console::WriteLine("id\tNatNumber Nombre\tGeneracion");
    for (int i =0; i<pokede->getZise(); i++)
    {
        InfoPo* poke = pokede->get(i); 

        String^ name = gcnew String(poke->getnombrePoke().c_str()); 

        Console::WriteLine("{0}\t{1}\t{2}\t{3}", poke->getid(), poke->getNatNum(),  name, poke->getgeneracion() );

    }
}

int main(array<System::String ^> ^args)
{
    int ReadOp; 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    Console::WriteLine("\t\t\tBienvenido a tu pokedex");
    Console::WriteLine("\tPodras encontrar una lista de Pokémons registrados");
regresar_menuPrin:
    Console::WriteLine("\n");
    Console::WriteLine(" \t\tIngrese 1 para entrar a la pokedex \n");
    try
    {
        ReadOp = Convert::ToInt32(Console::ReadLine());
    }
    catch (const std::string & error)
    {

    }
    switch (ReadOp)
    {
    case 1:
        system("cls");
        List<InfoPo> * Poke = readInfoPo("Poke.csv");
        Console::WriteLine("\t\tOrden original");
        showPoke(Poke);
        Console::WriteLine("\n");
        Console::WriteLine(" \tIngrese 1 para ordenar la pokedex por generacion \n");
        Console::WriteLine(" \tIngrese 2 para ordenar por National Number la pokedex \n");
        int menudo; 
        try
        {
            menudo = Convert::ToInt32(Console::ReadLine());
        }
        catch (const std::string & error)
        {

        }
        switch (menudo)
        {
        case 1:
            system("cls");
            Console::WriteLine("\t\tOrden por generacion\n");
         
            Poke = Poke->SelectionSort(new PokeGenComparator());
            showPoke(Poke);
            break;

        case 2:
            system("cls");
            Console::WriteLine("\tOrden por National Number\n");
            
            Poke = Poke->SelectionSort(new PokeNatNumComparator());
            showPoke(Poke);
            break; 
        }
        break;
    }

    return 0;

}
