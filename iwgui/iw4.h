#ifndef IW4_H
#define IW4_H

// TODO: reverse engine structures based on game
typedef class Font_s;
typedef class Material;
typedef class ScreenPlacement;

enum GameType { SP, MP };

extern ScreenPlacement* (*ScrPlace_GetActivePlacement)(int localClientNum);
extern Font_s* (*R_RegisterFont)(const char* fontPath, int imageTrack);
extern int(*R_TextWidth)(const char* string, int maxChars, Font_s* font);
extern int(*R_TextHeight)(Font_s* font);
extern void(*R_AddCmdDrawText)(const char* string, int maxChars, Font_s* font, float x, float y, float xScale, float yScale, float rotation, const float* color, int style);
extern void(*R_AddCmdDrawStretchPic)(float x, float y, float width, float height, float s1, float t1, float s2, float t2, const float* color, Material* material);
extern void(*CG_DrawRotatedPicPhysical)(ScreenPlacement* scrPlace, float x, float y, float width, float height, float rotation, const float* color, Material* material);
extern Material* (*Material_RegisterHandle)(const char* name, int imageTrack);

void IWGui_Init(GameType type);
void IWGui_Load(int scrplace_getactiveplacement, int r_registerfont, int r_textwidth, int r_textheight, int r_addcmddrawtext, int r_addcmddrawstretchpic, int cg_drawrotatedpicphysical, int material_registerhandle);


#endif /* IW4_H */