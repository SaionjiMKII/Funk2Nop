# Funk2Nop
After executing the function, replaces all bytes in it with NOP.

EN:
After executing the function, it replaces all bytes in it with NOP, which makes it impossible to restore the original dump.

RU:
После выполнения функции, заменяет все байты в ней NOP, что делает невозможным восстановление оригинального дампа.

![image](https://user-images.githubusercontent.com/92443330/216293787-fbf36c09-8e1b-45a9-a0dd-3920e461a00d.png)

Как узнать размер функции?
Открываем оригинальный файл в IDA -> ПКМ на нашу функцию -> Edit Function (CTRL + E).
![image](https://user-images.githubusercontent.com/92443330/216293998-0aa511b3-330d-4ad9-a233-0897caf5bf31.png)
Смотрим адреса:
![image](https://user-images.githubusercontent.com/92443330/216294052-b25fd3bd-5426-422c-bf35-85c4eae40bb9.png)
Открываем Calc.exe - режим Программист - Hex.
![image](https://user-images.githubusercontent.com/92443330/216294110-37f0ed8a-8e52-4b63-be86-c532c4736370.png)
Вводим End Address - Start Address
![image](https://user-images.githubusercontent.com/92443330/216294181-f071baaa-f6d4-4a2c-a9f3-9e550d71597f.png)
