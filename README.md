# Taller ArduinoEsp8266 y Ubidots

## instrucciones

### Creación cuenta en Ubidots
1. ingrese a la página de uBidots [app.ubidots.com](https://app.ubidots.com) y registrese (pestaña SING UP).
2. En la pagina de uBidots, seleccione la pestaña "Device" y luego haga click en "Add Device" como se muestra en la siguiente figura
![](images/2018/05/create_device.gif)
Luego asigne un nombre representativo al nuevo dispositivo. Esto creará una representación de nuestra tarjeta Esp8266 en nuestra cuenta de uBidots.

3. A continuación haga click en el dispositivo recien creado y agregue una variable mediante un click en "Add Variable", seleccione la opción "Default" y nombre esta variable como "temperatura".

![](images/2018/05/create_variable.gif)
4. Genere otra variable llamada "humedad".

5. Por último, cree una tercera variable llamada "led".

6. A continuación en la pestaña llamda "Dashboards", agregue un nuevo dashboard para su dispositivo, esto le permitirá visualizar y controlar los valores de sus variables. Cree un nuevo Dashboard, nombrelo adecudamente y luego haga click en él como se muestra en la figura.
![](images/2018/05/create_dashboard.gif)

7. Luego cree un "Widget" que nos permita observar la variable temeratura, para ello haga click en el icono !["Add Widget"](images/2018/05/add-new-icon.png), luego haga click en el tipo de indicador llamado "indicator" , luego seleccione el tipo de indicador llamado "Gauge" y acotinuación seleccione el dispositivo anteriormente creado, finalmente seleccione la variable temperatura del dispositivo e indique los valores máximos y mínimos permitidos, en este caso seleccione -10 y 45 (estos serán los límites en grados celsius). En la siguiente figura se muestra el procedimiento.
![](images/2018/05/create_widget_temperatura.gif)

8. De ma misma forma, cree un widget para la variable humedad, con límites entre 0 y 100.

9. finalmente cree otro widget del tipo switch para controlar la variable led. Haga clic en el icono !["Add Widget"](images/2018/05/add-new-icon.png), luego seleccione la clase de widget llamada "Control", a continuacion seleccione el tipo de widget llamado "switch" y luego el dispositivo anteriomente creado, seleccione la variable led haga click en el boton "finish".
![](images/2018/05/create_widget_switch.gif)

## Cableado y Programación de la tarjeta ESP8266

1. Arme el circuito de la siguiente figura para conectar el sensor de temperatura y humedad a la tarjeta.
![](images/2018/05/cableado_1_esp8266.png)

2. Conecte la tarjeta ESP8266 a su computador mediante un cable micro usb, deberá observar que el led del sensor se enciende inmediatamente, si esto no sucede desconecte de inmediato y revise sus conexiones.Luego mueva el interruptor de la tarjeta a la posición "ON".

3. Abrir el programa IDE de Arduino y configurarlo para la tarjeta utilizada, primero en el menu seleccione Herramientas->Placa->"sparkFun ESP8266 Thing Dev", luego seleccionar el puerto de comunicaciones en Herramientas->puerto->comX (la X es reemplazada según el número que aparesca en cada computador).
![](images/2018/05/configure_arduino.gif)
