# CppCombinedSettings
An example microsoft's (mostly in winapi) way of using a single byte to receive up to 8 booleans in function parameters.

for example, instead of :

void DrawRectangle(bool _useDefaultColor, bool _roundCorners, bool _stretchToScreen);
called this way :
DrawRectangle(true, false, true);

you will have :

void DrawRectangle(byte _settings);
called this way :
DrawRectangle(USE_DEFAULT_COLOR | STRETCH_TO_SCREEN);
