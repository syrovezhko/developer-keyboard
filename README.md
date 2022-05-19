# Предисловие

В данном руководстве будет рассказано и показано как установить всё необходимое для создания копии начинки нашего устройства.
Первым делом необходимо установить *ArduinoIDE*, в котором будет производиться работа с нашим продуктом.

<details>
<summary>Для дальнейших действий вам потребуется:</summary>

1.   Arduino Uno
2.   Digispark
3.   6 проводов для подключения к Arduino Uno и 9 проводов для подключения к кнопкам
4.   ПК
5.   Паяльник
6.   3D-принтер для печати корпуса
7.   Пластик для печати

</details>

<details>
<summary>

# Установка ArduinoIDE

</summary>

Данную программу можно найти на [оффициальном сайте компании Arduino](https://www.arduino.cc/en/software).

<details>
<summary>Фотография сайта Arduino.</summary>

![image](https://user-images.githubusercontent.com/102234463/166157753-82178e8b-a5e1-4c4c-9113-2db8609e7b74.png)
    
</details>

Скачиваем файл и начианем установку программы.
</details>

# Подготовка Digispark

Для того что бы использовать стандартный *Digispark* нам необходимо его перепрошить, так как изначально его пин *P5* используется как *Reset*.
Для этого нам необходимо установить *AVRDude*. Он содержится в пакете программ *WinAVR*. Скачать его можно с их [сайта](http://winavr.sourceforge.net/index.html). Переходим на вкладку *Download* и скачиваем и устанавливаем необоходимую нам программу.

<details>
<summary>При установке в окне с дополнительными функциями установки рекомендуется убрать галочку с последнего пункта, если вы не нуждаетесь в новом текстовом редакторе.</summary>

![image](https://user-images.githubusercontent.com/102234463/166182229-03588ff5-6582-4827-a518-08880f638cf6.png)
    
</details>

<details>
<summary>

## Превращение *Arduino Uno* в ISP-программатор

</summary>
Далее нам необходимо прошить одну из плат Arduino в качестве программатора. Как пример нами будет использоваться плата Arduino Uno.

<details>
<summary>Открываем ArduinoIDE и открываем уже готовый скетч программатора.</summary>

![image](https://user-images.githubusercontent.com/102234463/166183391-2d240e96-6c54-42f9-b889-5cd9acc0e34f.png)
    
</details>

<details>
<summary>Далее необходимо произвести преварительную настройку и выбрать всё необходимое во вкладке Инструменты</summary>

![image](https://user-images.githubusercontent.com/102234463/166183982-c10da803-119d-41c0-839b-1e8adfe63fa3.png)
    
</details>
    
</details>
<details>
<summary>

## Схема подключения Digispark к Arduino Uno

</summary>

    Arduino --> Digispark 
    GND     --> GND
    5v      --> 5v
    10      --> P5
    11      --> P0
    12      --> P1
    13      --> P2

</details>

## Снятие флага Reset с пина P5 Digispark
<details>
<summary>Открываем командную строку, используя комбинацию клавиш *Win+R* и написав в появившемся окне "cmd".</summary>

![image](https://user-images.githubusercontent.com/102234463/167291858-6eb4cd01-fcd5-4712-af97-73e1714f1aaa.png)

    
</details>
В ней мы прописываем две команды, где на месте *COMx* должен быть номер порта вашей *Arduino*. В нашем случае это *COM5*.

    avrdude -P COMx -b 19200 -c avrisp -p attiny85 -n
    avrdude -P COMx -b 19200 -p attiny85 -c avrisp  -U hfuse:w:0x5F:

Если после перепрошивания устройства *AVRDude* не выдал никаких ошибок, то можно двигаться дальше.
После того как мы успешно разблокировали пин *P5*, мы подключаем к плате 4 кнопки

    Digispark --> Кнопки
    P0        --> Первая    (CTRL)
    P1        --> Вторая    (WIN)
    P2        --> Третья    (C)
    P5        --> Четвертая (V)

# Установка ПО для работы с Digispark

Далее необходимо установить драйвера для работы с платами *Digistump*.
Найти их можно на [оффициальной странице GitHub Digistump](https://github.com/digistump/DigistumpArduino/releases), либо же сразу скачать [zip архив](https://github.com/digistump/DigistumpArduino/releases/download/1.6.7/Digistump.Drivers.zip), с их страницы GitHub.

<details>
<summary>Страница GitHub Digistump</summary>

![image](https://user-images.githubusercontent.com/102234463/166157907-c6353381-e389-466a-91b8-7fc6beb389b9.png)
    
</details>

Также скачиваем файлы, разархивируем их и запускаем файл *"Install Drivers.exe"* и производим установку драйверов.

<details>
<summary>

## Подготовка ArduinoIDE к работе с Digispark

</summary>

После всех проделанных нами действий необходимо добавить платы *Digistump* в *ArduinoIDE*.
Открываем вкладку *Файл* и заходим в настройки. Там указываем ссылку в строке для доп. ссылок менеджера плат.

    http://digistump.com/package_digistump_index.json

<details>
<summary>Путь к окну с дополнительными ссылками</summary>

![image](https://user-images.githubusercontent.com/102234463/166158270-bdd50854-a0db-421d-8b55-4f489ececadc.png)
![image](https://user-images.githubusercontent.com/102234463/166158395-d66af0d3-269b-442f-b805-67cbd09cbf74.png)
    
</details>

Далее необходимо установить платы *Digistump* в ПО *Arduino*.
<details>
<summary>Путь к менеджеру плат</summary>

![image](https://user-images.githubusercontent.com/102234463/166158639-11ce110c-5e59-44f6-91e4-255c234bd00c.png)
    
</details>

В новом окне в поисковой строке необходимо найти *"Digistump AVR boards"* и добавить их в *ArduinoIDE*.
<details>
<summary>Фотография окна с поиском плат</summary>

![image](https://user-images.githubusercontent.com/102234463/166158708-80052682-5223-47d1-917f-e57de0e9aef3.png)
    
</details>
</details>

# Прошивка Digispark

<details>
<summary>Примеры прошивки платы (кликабельно)</summary>

1.    [![image](https://user-images.githubusercontent.com/102234463/169318634-bf3b608f-a9a1-4039-baf8-870514fd14ec.png)](https://github.com/syrovezhko/developer-keyboard/blob/Sketches/Sketches/Combination.ino)
2.    [![image](https://user-images.githubusercontent.com/102234463/169318705-2eefb8ae-58b7-4541-b895-7f78f31a24dd.png)](https://github.com/syrovezhko/developer-keyboard/blob/Sketches/Sketches/CombinationReverse.ino)
3.    [![image](https://user-images.githubusercontent.com/102234463/169318804-22569a07-482e-4351-867b-a34d14c3a04e.png)](https://github.com/syrovezhko/developer-keyboard/blob/Sketches/Sketches/Standart.ino)
4.    [![image](https://user-images.githubusercontent.com/102234463/169318928-5bef4d5f-ca00-44a2-8b9b-4a4e969523a4.png)](https://github.com/syrovezhko/developer-keyboard/blob/Sketches/Sketches/StandartReverse.ino)
5.    [![image](https://user-images.githubusercontent.com/102234463/169318449-abbe1312-19ad-4b9a-8768-e020da428ce2.png)](https://github.com/syrovezhko/developer-keyboard/blob/Sketches/Sketches/Multimedia.ino)
6.    [![image](https://user-images.githubusercontent.com/102234463/169318552-8901e301-c754-40b0-a134-3c5459af44cd.png)](https://github.com/syrovezhko/developer-keyboard/blob/Sketches/Sketches/MultimediaReverse.ino)

</details>

Для прошивки нашего устройства необходимо выбрать плату *Digispark* в новой вкладке с платами.
<details>
<summary>Фотография выбора платы Digispark</summary>

![image](https://user-images.githubusercontent.com/102234463/166158847-3de4d9da-c890-4738-ac5e-dc8615075472.png)
    
</details>
    
### *При подключении к компьютеру устройство автомотически идентифицируется как HID-устройство, так что его можно использовать с любым ПК.*

#  Корпусные детали

Для создания 3D моделей использовалась программа Autodesk Fusion 360. Для печати рекомендуется применять данные настройки: Толщина стенки - 1.2 мм. Заполнение 20%. Высота слоя 0.1-0.15 мм

Ссылки для скачивания моделей:\
    Корпус - https://grabcad.com/library/housing-in-two-parts-1 \
    Keycap - https://grabcad.com/library/keycap-16

# Заключение

На этом данное руководство подоходит к концу, вы выполнили все действия, необходимые для работы с Клавиатурой Истинного Разработчика.
