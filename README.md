# skeleton
## Simple 2D application framework written in C++/SFML. 

## How to build
Download [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) and extract it to the *vendor/SFML* folder.

Download [premake5](https://premake.github.io/download.html) and remember it's location or add it to path


### Example: Generating Visual Studio 2019 solution and project files
```
  path/to/premake5.exe vs2019
  // or if the path to SFML is different than default
  path/to/premake5.exe --sfmlpath=path/to/SFML vs2019
```
Then compile it and run with Visual Studio

### Example: Generating Makefiles
```
  path/to/premake5.exe gmake2
  // or if the path to SFML is different than default
  path/to/premake5.exe --sfmlpath=path/to/SFML gmake2
```

After that
```
  make
  // after sucessful compilation
  cd Sandbox
  // it needs to be run from the projects root directory for now
  ..\bin\Debug-windows-x86\Sandbox\Sandbox.exe
```
### Other platforms and project files
For generating other project files or for different platforms head to this [link](https://github.com/premake/premake-core/wiki/Using-Premake)

### The main purpose of this project is to create a simple, beginner friendly app building framework.

As I like creating new programs in C++/SFML I decided to make an simple framework which will save me some time and help me especially at the beginning of the project. Often when creating a simple game I'm ending up with a problem of creating a simple menu with buttons, simple state managing etc. which led me to creating same classes all over again. This framework will provide me with all tools needed to build a simple sceleton of an app which includes buttons, state managing, popups etc.

What this framework will provide:
- Simple GUI classes,
- Simple state changing,
- Simple acces to fonts, textures, sounds,
- Controllers of input, buttons.
- Animations

More specific description of parts of my framework
- State Manager -> provides with simple state changin aswell as pushing state on the stack (only current state will be updated, all previous will be "frozen" until user comes back to them.
- Prompts -> will let the user choose one of at least one option. For example (Yes/No). Will accept user input aswell.
- Popup -> will be shown on the screen for a specific time

- Font/Texture/Sound Manager (as a simple ResourceManager) will provide you with a single copy of, lets say, a texture from every place in the program instead of you creating yourself more copies (saves time and memory, sounds and music will be cached (removed if not used))

- GUI classes such as:
  - Buttons -> can change on hover/click events. They contain callbacks which are called when an "click" event occurs. Callbacks are provided by user (for example if this button is clicked, StateManager will change state to MainGame)
  - Prompts, Popups (see above)
  - InputBox -> simple input box which lets you type in some text.
  
- Controllers:
  - Button Controller -> is able to place the buttons evenly on the screen, supports the keyboard and mouse navigation out of the box, updates and renders those buttons. It basicly takes care of buttons, so you don't need to worry about them. (It should be used in all sorts of menus where you need to place buttons, update them etc.)
  - Input Controller -> can be bound to any of the sen::Text object. It takes input from keyboard and updates the object, it also supports the Cursor.  Can also validate user input if specified by user.

The purpose of this project is not to build a begginer friendly physics engine but to build a begginer friendly app framework. 

### If you want to use a physics engine I highly recommend using  [BOX2D](https://github.com/erincatto/Box2D)
### If you want to use this sort of framework now I highly reccomend checking out [Hopson's SFML-game-framework](https://github.com/Hopson97/SFML-Game-Framework) (as he made his framework for similiar purposes, and it's a great example) 

# skeleton
Prosty framework tworzony w C++/SFMl.

Ponieważ lubię tworzyć nowe programy w C++/SFML zdecydowałem, że stworzę prosty framework, który ułatwi mi pracę i zaoszczedzi czas zwłaszcza na samym początku tworzenia nowego projektu. Często przy okazji pisania jakiejś gry spotykałem się z problemem stworzenia prostego menu lub opcji. Zawsze kończyło się to na tworzeniu przeróżnych klas przycisków, tekstu itd. Postanowiłem więc, że stworzę framework, który będzie mi zapewniał dostęp do narzędzi potrzebnych do zbudowania prostego szkieletu aplikacji w tym przyciski, menadżer stanów gry (np przejście z menu głównego do gry), popupy, menadżer dźwiękow, tekstur itp.

Co będzie zapewniać mój framewokr:
- Podstawowe klasy GUI,
- Podstawowa zmiana state'ow programu,
- Menadżer udostepniający czcionki, tekstury, z różnych miejsc w programie
- Controllery (inputu, przycisków)

Szczegółowy opis części elementów frameworku
- Menadżer stanów gry -> umożliwia łatwe przeniesienie gracza z np gry do menu głównego. Umożliwia też dokładanie stateów na stos, dzięki czemu gracz może cofać się w state'ach a one same nie są usuwane (przestają być tylko update'owane). Umożliwia także stworzenie popupa (więcej patrz: Popupy), albo powiadomienie (więcej patrz: Powiadomienia).
- Prompt -> w skrócie: działać bedą jak okna dialogowe w systemie windows.
- Popup -> w skrócie: bedą wyświetlać się (np. na dole ekranu) przez określony czas.

- Menedżer czcionek, tekstur, dźwiękow -> w celu uniknięcia tworzenia niewiadomo ilu takich samych tekstur, dźwięków menedżer będzie przechowywał jedną kopię elementu i udostepniał ją wszędzie gdzie bedzięmy potrzebować. Dźwięki i muzyka bedą usuwane z pamięci gdy
nie będą używane.

- Klasy GUI takie jak:
  - Przyciski -> mają kilka stanów (hover, click, standard), zmieniają wygląd zgodnie z nimi. Mogą przechowywać callbacki (funkcje które wykonują sie dopiero kiedy spełni się jakiś warunek),  które są wywoływane w momencie kliknięcia w przycisk.
  - Popupy, Powiadomienia (patrz wyżej)
  - InputBox -> pole, w które można wprowadzić dane. Można także podać funkcję walidująca wprowadzane dane.
 
 Controllery
  - Controller przyciskow -> potrafi ustawić je równo na ekranie, zapewnia obsługę klawiatury i myszy, update'uje i renderuje przyciski. Controller ma działać tak, że tworzymy przyciski, precyzujemy ich zachowanie, przekazujemy je controllerowi, a on je ustawia i sam update'uje, i renderuje. My zapominamy o przyciskach( Możemy wciąż korzystać z przycisków nie przekazując ich controllerowi. Controller przydaje się do wszelakich menu, opcji itd )
  - Controller inputu -> możemy go zbindować do dowolnego obiektu klasy sen::Text. Controller przechwytuje wszelkie eventy związane z inputem i update'uje zawartość obiektu

Celem tego projektu jest stworzenie frameworku przyjaznego w tworzeniu szkieletow aplikacji, natomiast nie jest celem stworzenie pełnoprawnego silnika fizycznego.

### Jeśli chcesz skorzystać z silnika fizycznego polecam [BOX2D](https://github.com/erincatto/Box2D)
### Jeśli chcesz skorzystać z *gotowego* na tę chwilę frameworku, który opiera się na podobnych zasadach co mój - sprawdź [Framework do Gier w SFML Hopson'a](https://github.com/Hopson97/SFML-Game-Framework) (jest dobrym przykładem jak wygląda gotowy framework do aplikacji w sfml) 
