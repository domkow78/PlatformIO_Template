# PlatformIO Template

Krótki szablon projektu embedded oparty o PlatformIO (C++), przygotowany jako baza do dalszego rozwoju firmware.

## Co zawiera projekt

- modularną strukturę (`src`, `include`, `lib`, `test`, `docs`, `hardware`),
- podstawowe komponenty aplikacji (`Application`, `Board`, `Logger`),
- konfigurację środowiska w pliku `platformio.ini`.

## Szybki start

1. Otwórz projekt w VS Code z rozszerzeniem PlatformIO.
2. Zbuduj projekt:

	```bash
	pio run
	```

3. Wgraj firmware:

	```bash
	pio run -t upload
	```

4. (Opcjonalnie) monitor portu szeregowego:

	```bash
	pio device monitor
	```

## Dokumentacja

Szczegóły organizacji i plan rozwoju znajdują się w katalogu `docs/`.
