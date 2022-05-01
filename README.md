В данном руководстве будет рассказано и показано как установить всё необходимое для перепрограмирования нашего устройства.
Первым делом необходимо установить ArduinoIDE, в котором будет производиться работа с нашим продуктом.
Найти данную программу можно найти на оффициальном сайте компании Arduino.

https://www.arduino.cc/en/software
![image](https://user-images.githubusercontent.com/102234463/166157753-82178e8b-a5e1-4c4c-9113-2db8609e7b74.png)

Скачиваем файл и начианем установку программы.

Далее необходимо установить драйвера для работы с платами Digistump.
Вы можете найти их на оффициальной странице GitHub Digistump, либо же сразу скачать zip архив, скачанный с их страницы GitHub и добавленный сюда.

[Digistump.Drivers.zip](https://github.com/syrovezhko/developer-keyboard/files/8599401/Digistump.Drivers.zip)

https://github.com/digistump/DigistumpArduino/releases
![image](https://user-images.githubusercontent.com/102234463/166157907-c6353381-e389-466a-91b8-7fc6beb389b9.png)

Также скачиваем файлы, разархивируем их и запускаем файл "Install Drivers.exe" и соглашаемся со всем что нам предлагают.

После всех проделанных нами действий нам необходимо добавить платы Digistump в ArduinoIDE.
Открываем вкладку Файл и заходим в настройки приложения. Там указываем ссылку в строке для доп. ссылок менеджера плат.
http://digistump.com/package_digistump_index.json

![image](https://user-images.githubusercontent.com/102234463/166158270-bdd50854-a0db-421d-8b55-4f489ececadc.png)
![image](https://user-images.githubusercontent.com/102234463/166158395-d66af0d3-269b-442f-b805-67cbd09cbf74.png)

Далее необходимо установить платы Digistump в ПО Arduino.
![image](https://user-images.githubusercontent.com/102234463/166158639-11ce110c-5e59-44f6-91e4-255c234bd00c.png)

В новом окне в поисковой строке необходимо найти "Digistump AVR boards" и добавить их в ArduinoIDE.
![image](https://user-images.githubusercontent.com/102234463/166158708-80052682-5223-47d1-917f-e57de0e9aef3.png)

Далее при перепрограмировании нашего устройства необходимо будет выбирать плату Digispark в новой вкладке с платами.
![image](https://user-images.githubusercontent.com/102234463/166158847-3de4d9da-c890-4738-ac5e-dc8615075472.png)

На этом данное руководство подоходит к концу, вы установили всё необходимое для работы с Клавиатурой Истинного Разработчика.
