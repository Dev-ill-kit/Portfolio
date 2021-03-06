using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TerminalControl : MonoBehaviour
{
     
     int level;
     string password;
     string menuHint = "Напишите \"меню\", чтобы вернуться назад";
     string[] Level1passwords = {"ключ","книга","шкаф","ручка","текст"};
     string[] Level2passwords = {"дубинка","арест","закон","рапорт","начальник"};
     string[] Level3passwords = {"спутник","комета","орион","интерстеллар","космонавт"};
    enum Screen {MainMenu,Password,Win};
    Screen currentScreen = Screen.MainMenu;
    void Start()
    {
    ShowMainMenu("мой юный взломщик");


        }
    
    void ShowMainMenu(string playerName){
    currentScreen = Screen.MainMenu;
    level = 0;
   
    Terminal.ClearScreen();
    Terminal.WriteLine("Привет, "+playerName+ "!");
    Terminal.WriteLine("Какой терминал вы хотите \nвзломать сегодня?");
    Terminal.WriteLine(" ");
    Terminal.WriteLine($"Введите 1 - городская библиотека.");
    Terminal.WriteLine($"Введите 2 - полицейский участок."); 
    Terminal.WriteLine($"Введите 3 - космический корабль.");
    Terminal.WriteLine("Введите ваш выбор:");
    
    }
   
    void OnUserInput(string input)
	{
        input = input.ToLower();
        if(input == "меню"){
            ShowMainMenu("рад видеть тебя снова");
        }
        else if(currentScreen == Screen.MainMenu){
		RunMainMenu(input);  
    }
        else if(currentScreen == Screen.Password){
            CheckPassword(input);
        }	
    }
 
 void RunMainMenu(string input){
        bool isValidLevelNumber = (input == "1" || input == "2" || input == "3");
        if(isValidLevelNumber){
            level = int.Parse(input);
            GameStart();
        }
        else{
            Terminal.WriteLine("Введите правильное значение");
            }
        switch(input){
            case "007":
            Terminal.WriteLine("Привет Агент!");
            break;
            case "harry potter":
            Terminal.WriteLine("Авада Кедавра, грязнокровка!");
            break;
            
            
        }
 }
 void CheckPassword(string input){
    
     if(input == password){
         ShowWinScreen();
              }
     else {
         GameStart();
        
     }         

}

void ShowWinScreen(){
    Terminal.ClearScreen();
    Reward();
}

void Reward(){
    currentScreen = Screen.Win;
    switch (level){
        case 1:
        Terminal.WriteLine("Пароль верный! Держите вашу книгу:");
        Terminal.WriteLine(
            @"
    _______
   /      /,
  /      //
 /______//
(______(/
            ");
        break;
        case 2:
Terminal.WriteLine("Пароль верный! Вот ваше оружие:");
        Terminal.WriteLine(
            @"
   __,_____
  / __.==--)
 /#(-'
 `-'
            ");
        break;
        case 3:
        Terminal.WriteLine("Пароль верный! Можете посмотреть на ваш дом \nв телескоп:");
        Terminal.WriteLine(
            @"
     _______                            
 |==|_______D                          
       /|\                  ");
            break;
    }
    Terminal.WriteLine(menuHint);
}
void GameStart(){
    
       Terminal.ClearScreen();
    switch(level){
        case 1:
        password = Level1passwords[Random.Range(0,Level1passwords.Length)];
        Terminal.WriteLine("Вы в городской библиотеке");
        break;
        case 2:
        password = Level2passwords[Random.Range(0,Level2passwords.Length)];
        Terminal.WriteLine("Вы в полицейском участке");
        break;
        case 3:
        password = Level3passwords[Random.Range(0,Level3passwords.Length)];
        Terminal.WriteLine("Вы на космическом корабле");
        break;
        default:
        Debug.LogError("Такого уровня не существует");
        break;
    }
    currentScreen = Screen.Password;
       

    Terminal.WriteLine("Подсказка :"+password.Anagram());
    Terminal.WriteLine(menuHint);
    Terminal.WriteLine("Введите пароль:");


}

}




 


 
    

