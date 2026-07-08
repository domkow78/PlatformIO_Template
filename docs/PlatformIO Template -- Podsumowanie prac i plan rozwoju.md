# PlatformIO Template -- Podsumowanie prac i plan rozwoju

**Data:** 2026-07-08

## Cel

Celem jest stworzenie własnego szablonu projektu PlatformIO, który
będzie wykorzystywany we wszystkich przyszłych projektach (Arduino,
ESP32, Raspberry Pi Pico i inne).

Projekt ma stanowić bazę do budowy własnego frameworka embedded.

------------------------------------------------------------------------

# Co zostało wykonane

## Środowisko

-   Zainstalowano Visual Studio Code.
-   Zainstalowano PlatformIO.
-   Dodano polecenie `pio` do zmiennej `PATH`.
-   Zweryfikowano działanie:
    -   `pio --version`
    -   `pio project init`
    -   `pio run`

------------------------------------------------------------------------

## Git

-   Utworzono lokalne repozytorium.
-   Wypchnięto projekt do zdalnego repozytorium.
-   Zweryfikowano poprawne działanie `git push`.

------------------------------------------------------------------------

## Struktura projektu

Obecna struktura:

``` text
Projekt/
│
├── docs/
├── hardware/
├── include/
├── lib/
│   ├── Board/
│   └── Logger/
├── scripts/
├── src/
│   ├── main.cpp
│   ├── Application.cpp
│   └── Application.h
├── test/
│
├── .gitignore
├── README.md
└── platformio.ini
```

------------------------------------------------------------------------

## Pliki konfiguracyjne

Utworzono:

-   config.h
-   pins.h
-   project.h
-   version.h

Ich zadania:

-   **config.h** -- konfiguracja projektu
-   **pins.h** -- definicje pinów
-   **version.h** -- wersja firmware
-   **project.h** -- wspólny nagłówek projektu

------------------------------------------------------------------------

## Logger

Powstała pierwsza własna biblioteka.

    lib/
    └── Logger/

Na obecnym etapie:

-   inicjalizacja `Serial`
-   wysyłanie komunikatów

W przyszłości:

-   poziomy logowania
-   timestamp
-   możliwość wyłączenia logów
-   zapis do pliku / MQTT / Wi-Fi

------------------------------------------------------------------------

## Board

Powstał moduł:

    lib/
    └── Board/

Odpowiada za:

-   inicjalizację sprzętu
-   konfigurację pinów
-   uruchomienie Loggera

Docelowo będzie również zawierał:

-   Wire
-   SPI
-   Watchdog
-   EEPROM
-   konfigurację zależną od płytki

------------------------------------------------------------------------

# Najważniejsze założenia architektury

Przyjęto zasadę:

-   `main.cpp` ma być możliwie najmniejszy.
-   Inicjalizacja sprzętu trafia do `Board`.
-   Logika programu trafia do `Application`.
-   Kod wielokrotnego użytku trafia do `lib`.

------------------------------------------------------------------------

# Docelowa architektura

``` text
Application
      │
      ▼
Services
      │
      ▼
Devices
      │
      ▼
Drivers
      │
      ▼
Board
```

------------------------------------------------------------------------

# Plan dalszych prac

## Etap 1

Dokończenie klasy `Application`.

Docelowo:

-   `Application::begin()`
-   `Application::run()`

`main.cpp` powinien zawierać wyłącznie:

``` cpp
void setup()
{
    Board::init();
    app.begin();
}

void loop()
{
    app.run();
}
```

------------------------------------------------------------------------

## Etap 2

Rozbudowa `Logger`.

Planowane funkcje:

-   info()
-   warning()
-   error()
-   debug()

------------------------------------------------------------------------

## Etap 3

Rozbudowa `Board`.

Dodanie:

-   Wire
-   SPI
-   Watchdog
-   konfiguracji zależnej od platformy

------------------------------------------------------------------------

## Etap 4

Pierwsze uniwersalne moduły:

-   Timer
-   Button
-   Relay

------------------------------------------------------------------------

## Etap 5

Sterowanie urządzeniami:

-   Pump
-   Motor
-   Sensor

------------------------------------------------------------------------

## Etap 6

Komunikacja:

-   UART
-   I²C
-   SPI
-   CAN
-   MQTT
-   Wi-Fi
-   BLE

------------------------------------------------------------------------

## Etap 7

Wyświetlacze i interfejs użytkownika.

------------------------------------------------------------------------

## Etap 8

Testy jednostkowe.

------------------------------------------------------------------------

## Etap 9

Automatyzacja:

-   wersjonowanie
-   skrypty
-   release
-   flash

------------------------------------------------------------------------

# Zasady projektu

1.  Jeden projekt = jedno repozytorium Git.
2.  Jeden moduł = jedna odpowiedzialność.
3.  Nie tworzyć katalogów „na zapas".
4.  Dodawać moduły dopiero wtedy, gdy pojawi się rzeczywista potrzeba.
5.  `main.cpp` powinien pozostawać możliwie prosty.
6.  Wszystkie nowe elementy mają być możliwe do ponownego wykorzystania.

------------------------------------------------------------------------

# Cel końcowy

Stworzenie własnego, lekkiego frameworka embedded opartego o PlatformIO,
wykorzystywanego we wszystkich przyszłych projektach, rozwijanego
stopniowo wraz z kolejnymi realizacjami.
