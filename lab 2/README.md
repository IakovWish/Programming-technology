Необходимо выполнить разделение на h и cpp файлы для каждого класса. h файлы содержат определение, cpp файлы содержат реализацию. функция main обязана располагаться в отдельном cpp файле.
Элемент очереди содержит данные и ссылку на следующий. Элемент реализовать с помощью класса или структуры. В классе или структуре, реализующей элемент, необходимо поместить функции для установки и извлечения данных. То есть напрямую обращения к данным и ссылке(-ам) быть не должно.
Необходимо работать с динамическим выделением памяти. Важно выделять и всегда очищать выделенную память.
Необходимо написать для каждого класса: конструктор с параметрами и без параметров, конструктор копирования, деструктор, необходимо продемонстрировать применение спецификатора explicit.
Требуется реализовать методы/функции с аргументами по умолчанию.
Реализовать пользовательское меню согласно заданию. В пользовательском меню обязательно предоставить пользователю возможность взаимодействовать со всеми настраиваемыми параметрами. То есть не должно существовать в программе числовых или буквенных констант, которые могут быть введены пользователем.
Номер варианта соответствует номеру студента в списке. Каждому студенту необходимо выполнить оба задания.
Задание 1. Унарная операция
Создать объект типа очередь;
++(постфиксная форма, метод) добавляет элемент в очередь;
-- (постфиксная форма, метод) вытаскивает элемент из очереди;
++(префиксная форма, дружественная функция) увеличивает все числа в очереди на 1;
-- (префиксная форма, дружественная функция) уменьшает все числа в очереди на 1;
Оператор ! проверяет очередь на пустоту.
Задание 2. Бинарная операция
Создать класс координат;
Определить оператор + как метод и - как дружественную функцию;
Должно быть доступно сложение и вычитание координат с другим экземпляром вашего класса и с числом;
Перегрузить оператор сравнения (поэлементное) ==, !=;
Перегрузить ввод в поток и вывод из потока.
