This is an automatic translation, may be incorrect in some places. See sources and examples!

# clap
### The library is incompatible with the current version of VolAnalyzer
Library for detecting claps into a microphone (recommended in conjunction with VolAnalyzer.h)
- Non-blocking polling
- Counts the number of claps

### Compatibility
Compatible with all Arduino platforms (using Arduino functions)

## Content
- [Install](#install)
- [Initialization](#init)
- [Usage](#usage)
- [Example](#example)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found by the name **Clap** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download library](https://github.com/GyverLibs/Clap/archive/refs/heads/main.zip) .zip archive for manual installation:
    - Unzip and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unzip and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/*
    - (Arduino IDE) automatic installation from .zip: *Sketch/Include library/Add .ZIP library…* and specify the downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE% D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Initialization
```cpp
clap clap;
```

<a id="usage"></a>
## Usage
```cpp
void tick(int val); // call into the loop, pass the current volume
void setTrsh(int trsh); // set volume threshold
void setTimeout(int tout); // set last clap timeout
bool isClap(); // check for cotton
bool hasClaps(uint8_t claps); // there is a specified number of claps
bool hasClaps(); // there are some pops
uint8_t getClaps(); // get the number of claps
```

<a id="example"></a>
## Example
```cpp
// recognition of the number of claps

#include <VolAnalyzer.h>
#include <clap.h>

VolAnalyzer vol(A0); // microphone on A0
clap clap;

void setup() {
  Serial.begin(115200);
}

void loop() {
  vol.tick();
  clap.tick(vol.getRawMax());
  if (clap.isClap()) Serial.println("clap");
  if (clap.hasClaps(1)) Serial.println("1 clap");
  if (clap.hasClaps(2)) Serial.println("2 clap");
  if (clap.hasClaps(3)) Serial.println("3 clap");
}
```

<a id="versions"></a>
## Versions
- v1.0

<a id="feedback"></a>
## Bugs and feedback
When you find bugs, create an **Issue**, or better, immediately write to the mail [alex@alexgyver.ru](mailto:alex@alexgyver.ru)
The library is open for revision and your **Pull Request**'s!