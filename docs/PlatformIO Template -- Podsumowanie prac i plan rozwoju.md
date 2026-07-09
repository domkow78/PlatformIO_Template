# PlatformIO Template -- Podsumowanie prac i plan rozwoju

**Data aktualizacji:** 2026-07-09  
**Status dokumentu:** aktywny (wersja robocza)

## 1. Cel

Celem jest stworzenie własnego, lekkiego szablonu projektu PlatformIO, który będzie wykorzystywany w kolejnych projektach embedded (Arduino, ESP32, RP2040/Pico i inne).

Szablon ma być fundamentem pod rozwój własnego frameworka embedded: modularnego, testowalnego i możliwego do ponownego użycia.

---

## 2. Zakres

Zakres szablonu obejmuje:

- spójną strukturę repozytorium,
- podstawową architekturę warstwową,
- moduły bazowe (`Board`, `Application`, `Logger`),
- konwencje konfiguracji i wersjonowania,
- gotowość pod testy, automatyzację i release.

Poza zakresem (na ten etap):

- zaawansowany RTOS,
- pełna standaryzacja protokołów przemysłowych,
- rozbudowane GUI/HMI.

---

## 3. Co zostało wykonane

### 3.1 Środowisko

- Zainstalowano Visual Studio Code.
- Zainstalowano PlatformIO.
- Dodano `pio` do `PATH`.
- Zweryfikowano działanie:
  - `pio --version`
  - `pio project init`
  - `pio run`

### 3.2 Git

- Utworzono lokalne repozytorium.
- Wypchnięto projekt do repozytorium zdalnego.
- Potwierdzono poprawne działanie `git push`.

### 3.3 Struktura projektu

Utrzymywany jest podział na katalogi: `docs`, `hardware`, `include`, `lib`, `scripts`, `src`, `test` oraz pliki bazowe (`platformio.ini`, `README.md`, `.gitignore`).

### 3.4 Konfiguracja

Utworzono pliki:

- `config.h` -- konfiguracja projektu,
- `pins.h` -- definicje pinów,
- `version.h` -- wersja firmware,
- `project.h` -- wspólny nagłówek projektu.

### 3.5 Moduły bazowe

`Logger`:

- inicjalizacja `Serial`,
- podstawowe wysyłanie komunikatów.

`Board`:

- inicjalizacja sprzętu,
- konfiguracja pinów,
- uruchomienie loggera.

---

## 4. Założenia architektury

Zasady:

- `main.cpp` pozostaje minimalny,
- sprzęt i inicjalizacja niskiego poziomu są w `Board`,
- logika aplikacji jest w `Application`,
- kod wielokrotnego użycia trafia do `lib`.

Docelowy przepływ warstw:

```text
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

---

## 5. Standardy techniczne

### 5.1 Konwencje kodu

- Jeden moduł = jedna odpowiedzialność (SRP).
- API modułów powinno być małe i jawne.
- Brak logiki biznesowej w `main.cpp`.
- Zmiany publicznego API wymagają aktualizacji dokumentacji.

### 5.2 Obsługa błędów

- Każdy moduł zwraca status operacji (tam, gdzie to zasadne).
- Błędy krytyczne: log + bezpieczny fallback.
- Logi błędów mają zawierać kontekst modułu i kod błędu.

### 5.3 Logowanie

Minimalny format logu:

`[LEVEL] [MODULE] message`

Docelowe poziomy:

- `DEBUG`
- `INFO`
- `WARNING`
- `ERROR`

---

## 6. Matryca wsparcia platform (MVP)

| Platforma | Status | Uwagi |
|---|---|---|
| Arduino AVR | W trakcie | Bazowy punkt startowy |
| ESP32 | Planowane | Priorytet wysoki |
| RP2040 / Pico | Planowane | Priorytet średni |

---

## 7. KPI (mierzalne cele jakości)

- Build projektu przechodzi lokalnie: **100%**.
- Czas pełnego buildu (docelowo): **< 90 s** na standardowym stanowisku.
- Pokrycie testami modułów bazowych (`Logger`, `Application`): **>= 60%** (MVP).
- Rozmiar firmware (MVP): monitorowany i raportowany przy release.

---

## 8. Plan dalszych prac (z kryteriami akceptacji)

## Etap 1 -- Domknięcie `Application`

Zakres:

- `Application::begin()`
- `Application::run()`

Kryterium akceptacji:

- `main.cpp` wywołuje tylko `Board::init()`, `app.begin()`, `app.run()`.
- Build przechodzi bez błędów dla aktywnego środowiska PlatformIO.

## Etap 2 -- Rozbudowa `Logger`

Zakres:

- `info()`, `warning()`, `error()`, `debug()`

Kryterium akceptacji:

- wszystkie poziomy logowania działają,
- istnieje możliwość wyłączenia `DEBUG` kompilacyjnie.

## Etap 3 -- Rozbudowa `Board`

Zakres:

- integracja `Wire`, `SPI`, `Watchdog`,
- konfiguracja zależna od platformy.

Kryterium akceptacji:

- uruchomienie na min. 2 platformach z matrycy wsparcia,
- brak zmian w API `Application` przy zmianie platformy.

## Etap 4 -- Moduły uniwersalne

Zakres:

- `Timer`, `Button`, `Relay`

Kryterium akceptacji:

- każdy moduł ma prosty przykład użycia,
- każdy moduł ma test(y) jednostkowe lub testy integracyjne MVP.

## Etap 5 -- Urządzenia

Zakres:

- `Pump`, `Motor`, `Sensor`

Kryterium akceptacji:

- moduły korzystają z warstwy `Devices` i nie łamią granic warstw.

## Etap 6 -- Komunikacja

Zakres:

- `UART`, `I2C`, `SPI`, `CAN`, `MQTT`, `Wi-Fi`, `BLE`

Kryterium akceptacji:

- przynajmniej 2 kanały komunikacji dostarczone end-to-end (MVP).

## Etap 7 -- UI / Display

Kryterium akceptacji:

- co najmniej 1 spójny interfejs użytkownika dla platformy docelowej.

## Etap 8 -- Testy i jakość

Kryterium akceptacji:

- testy automatyczne uruchamiane lokalnie,
- raport z wynikami testów i podstawowych metryk.

## Etap 9 -- Automatyzacja

Zakres:

- wersjonowanie,
- skrypty,
- release,
- flash.

Kryterium akceptacji:

- powtarzalny proces release opisany w dokumentacji i zweryfikowany praktycznie.

---

## 9. Ryzyka i działania zapobiegawcze

1. **Ryzyko:** różnice między platformami (API, peryferia).  
   **Mitigacja:** warstwa abstrakcji + testy na min. 2 platformach.

2. **Ryzyko:** rozrost kodu i utrata spójności.  
   **Mitigacja:** SRP, przeglądy modułów, jasne granice warstw.

3. **Ryzyko:** brak regularnych testów.  
   **Mitigacja:** szybkie testy modułów bazowych już od wczesnych etapów.

---

## 10. ADR -- rejestr decyzji architektonicznych

Każda ważna decyzja architektoniczna powinna mieć wpis ADR:

- Data,
- Kontekst,
- Decyzja,
- Konsekwencje,
- Status (proponowana/zaakceptowana/zastąpiona).

---

## 11. Zasady projektu

1. Jeden projekt = jedno repozytorium Git.
2. Jeden moduł = jedna odpowiedzialność.
3. Nie tworzyć katalogów „na zapas”.
4. Dodawać moduły dopiero przy realnej potrzebie.
5. `main.cpp` powinien pozostawać możliwie prosty.
6. Wszystkie nowe elementy muszą być możliwe do ponownego użycia.

---

## 12. Cel końcowy

Stworzenie własnego, lekkiego frameworka embedded opartego o PlatformIO, rozwijanego iteracyjnie i wykorzystywanego we wszystkich kolejnych projektach.
