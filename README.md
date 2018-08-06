# SimpleENgine
## WORK IN PROGRESS. Simple 2D application engine/framework written in C++/SFML. 

### Not an physics engine | The main purpose of this project is to create a simple, beginner friendly app sceleton building engine.

As I like creating new programs in C++/SFML I decided to make an simple engine/framework which will save me some time and help me especially at the beginning of the project. Often when creating a simple game I'm ending up with a problem of creating a simple menu with buttons, simple state managing etc. which led me to creating same classes all over again. This engine will provide me with all tools needed to build a simple sceleton of an app which includes buttons, state managing, popups etc.

What this engine will provide:
- Simple UI classes,
- Simple state changing,
- Simple acces to fonts, textures, sounds,
- Controllers of input, buttons.

More specific description of parts of my engine
- State Manager -> provides with simple state changin aswell as pushing state on the stack (only current state will be updated, all previous will be "frozen" until user comes back to them.
- Popups -> all sorts of prompts (Yes/No) (Accept) (User input) etc,
- Notifications -> will be shown on the screen for a specific time

- Font/Texture/Sound Manager (as a simple ResourceManager) will provide you with a single copy of, lets say, a texture from every place in the program instead of you creating yourself more copies (saves time and memory)

- UI classes such as:
  - Buttons -> can change on hover/click events. They contain callbacks which are called when an "click" event occurs. Callbacks are provided by user (for example if this button is clicked, StateManager will change state to MainGame)
  - Popups, Notifications (see above)
  - InputBox -> simple input box which lets you type in some text. Can also validate user input if specified by user.
  
- Controllers:
  - Button Controller -> is able to place the buttons evenly on the screen, supports the keyboard and mouse navigation out of the box, updates and renders those buttons. It basicly takes care of buttons, so you don't need to worry about them. (It should be used in all sorts of menus where you need to place buttons, update them etc.)
  - Input Controller -> can be bound to any of the sen::Text object. It takes input from keyboard and updates the object, it also supports the Cursor.
  
What this engine won't provide
- Anything based on physics. The purpose of this project is not to build a begginer friendly physics engine but to build a begginer friendly app builder. 

### This project uses [nlohmann's json class](https://github.com/nlohmann/json) which introduces json in modern c++.
### If you want to use a physics engine I highly recommend using  [BOX2D](https://github.com/erincatto/Box2D) (you can still use my engine/framework for UI, state managing etc.)
### If you want to use this sort of engine now I highly reccomend checking out [Hopson's SFML-game-framework](https://github.com/Hopson97/SFML-Game-Framework) (as he made his framework for similiar purposes, and it's a great example) 
## Keep in mind that this project is still work in progress.

# SimpleENgine
## PROJEKT WCIĄŻ ROZWIJANY. Prosty silnik/framework tworzony w C++/SFMl.

Ponieważ lubię tworzyć nowe programy w C++/SFML zdecydowałem, że stworzę prosty silnik/framework, który ułatwi mi pracę i zaoszczedzi czas zwłaszcza na samym początku tworzenia nowego projektu. Często przy okazji pisania jakiejś gry spotykałem się z problemem stworzenia prostego menu lub opcji. Zawsze kończyło się to na tworzeniu przeróżnych klas przycisków, tekstu itd. Postanowiłem więc, że stworzę silnik, który będzie mi zapewniał dostęp do narzędzi potrzebnych do zbudowania prostego szkieletu aplikacji w tym przyciski, menadżer stanów gry (np przejście z menu głównego do gry), popupy menadżer dźwiękow, tekstur itp.

Co będzie zapewniać mój silnik:
- Podstawowe klasy UI,
- Podstawowa zmiana state'ow programu,
- Menadżer udostepniający czcionki, tekstury, z różnych miejsc w programie
- Controllery (inputu, przycisków)

Szczegółowy opis części elementów silnika
- Menadżer stanów gry -> umożliwia łatwe przeniesienie gracza z np gry do menu głównego. Umożliwia też dokładanie stateów na stos, dzięki czemu gracz może cofać się w state'ach a one same nie są usuwane (przestają być tylko update'owane). Umożliwia także stworzenie popupa (więcej patrz: Popupy), albo powiadomienie (więcej patrz: Powiadomienia).
- Popupy -> w skrócie: działać bedą jak okna dialogowe w systemie windows.
- Powiadomienia -> w skrócie: bedą wyświetlać się (np. na dole ekranu) przez określony czas.

- Menedżer czcionek, tekstur, dźwiękow -> w celu uniknięcia tworzenia niewiadomo ilu takich samych tekstur, dźwięków menedżer będzie przechowywał jedną kopię elementu i udostepniał ją wszędzie gdzie bedzięmy potrzebować

- Klasy UI takie jak:
  - Przyciski -> mają kilka stanów (hover, click, standard), zmieniają wygląd zgodnie z nimi. Mogą przechowywać callbacki (funkcje które wykonują sie dopiero kiedy spełni się jakiś warunek),  które są wywoływane w momencie kliknięcia w przycisk.
  - Popupy, Powiadomienia (patrz wyżej)
  - InputBox -> pole, w które można wprowadzić dane. Można także podać funkcję walidująca wprowadzane dane.
 
 Controllery
  - Controller przyciskow -> potrafi ustawić je równo na ekranie, zapewnia obsługę klawiatury i myszy, update'uje i renderuje przyciski. Controller ma działać tak, że tworzymy przyciski, precyzujemy ich zachowanie, przekazujemy je controllerowi, a on je ustawia i sam update'uje, i renderuje. My zapominamy o przyciskach( Możemy wciąż korzystać z przycisków nie przekazując ich controllerowi. Controller przydaje się do wszelakich menu, opcji itd )
  - Controller inputu -> możemy go zbindować do dowolnego obiektu klasy sen::Text. Controller przechwytuje wszelkie eventy związane z inputem i update'uje zawartość obiektu
  
  
Czego silnik zapewniać nie będzie:
- Czegokolwiek związanego z fizyką. Celem tego projektu jest stworzenie silnika/frameworku przyjaznego w tworzeniu szkieletow aplikacji, UI itd. natomiast nie jest celem stworzenie pełnoprawnego silnika fizycznego.

### Ten projekt korzysta z [klasy json](https://github.com/nlohmann/json) która wprowadza obiekty json znane z javascriptu do nowoczesnego c++.
### Jeśli chcesz skorzystać z silnika fizycznego polecam [BOX2D](https://github.com/erincatto/Box2D) (wciąż możesz korzystać z mojego silnika w celu tworzenia UI, zmiany state'ow itp)
### Jeśli chcesz skorzystać z *gotowego* na tę chwilę silnika/frameworka, który opiera się na podobnych zasadach co mój - sprawdź [Framework do Gier w SFML Hopson'a](https://github.com/Hopson97/SFML-Game-Framework) (jest dobrym przykładem jak wygląda gotowy framework do aplikacji w sfml) 

## Proszę mieć na uwadze, że projekt jest wciąż rozwijany
