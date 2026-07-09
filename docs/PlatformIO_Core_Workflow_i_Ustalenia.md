# PlatformIO Core -- workflow i ustalenia

**Data:** 2026-07-09  
**Status:** obowiązujące ustalenia

## 1. Decyzja

Podstawowym środowiskiem pracy jest:

- Visual Studio Code jako edytor,
- PlatformIO Core (`pio`) jako system budowania,
- Git jako system kontroli wersji.

Rozszerzenie PlatformIO IDE **nie jest wymagane**.

## 2. Uzasadnienie

- `pio project init` działa poprawnie.
- `pio run` kompiluje projekt.
- Projekty mogą być rozwijane bez PlatformIO IDE.
- Podejście jest wygodne w środowisku firmowym (np. proxy, polityki instalacji).

## 3. Wymagania wstępne

- Python + `pip`
- PlatformIO Core (`pio` w `PATH`)
- Git
- Sterowniki USB/UART dla używanej płytki
- Dostęp do właściwego portu (`COMx` na Windows)

## 4. Quick start (checklista)

1. Inicjalizacja projektu
2. Kompilacja
3. Wgranie firmware
4. Podgląd logów (monitor)
5. Commit i push zmian

## 5. Standardowy workflow

### 5.1 Utworzenie projektu

```bash
git init
pio project init --board nanoatmega328
```

### 5.2 Kompilacja

```bash
pio run
```

### 5.3 Wgrywanie

```bash
pio run -t upload
```

lub z portem:

```bash
pio run -t upload --upload-port COM5
```

### 5.4 Monitor portu szeregowego

```bash
pio device monitor --baud 115200
```
where pio
lub z portem:

```bash
pio device monitor -p COM5 --baud 115200
```

### 5.5 Czyszczenie

```bash
pio run -t clean
```

### 5.6 Aktualizacja pakietów

```bash
pio pkg update
```

### 5.7 Git

```bash
git add .
git commit -m "Opis zmian"
git push
```

## 6. Przydatne polecenia

```bash
pio boards
pio boards nano
pio system info
pio device list
pio project config
pio upgrade
```

## 7. Instalacja w środowisku firmowym (przykład)

PlatformIO Core można instalować ręcznie przez `pip`.  
Poniższa komenda to **przykład lokalny dla środowiska z proxy**:

```bash
python -m pip install -U platformio --proxy http://rb-proxy-de.bsh.corp.bshg.com:8080/ --index-url https://pypi.org/simple --trusted-host pypi.org --trusted-host files.pythonhosted.org
```

Po instalacji codzienna praca odbywa się przez polecenie `pio`.

## 8. Kierunek rozwoju

Framework będzie rozwijany tak, aby wymagał jedynie:

- PlatformIO Core,
- Git,
- dowolnego edytora (VS Code, Cursor, Windsurf).

Dzięki temu rozwiązanie pozostaje przenośne między komputerami i środowiskami.