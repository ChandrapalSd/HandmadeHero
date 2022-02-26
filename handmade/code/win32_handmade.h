#pragma once

struct win32_window_dimension
{
    int Width;
    int Height;
};

struct win32_sound_output
{
    int SamplesPerSecond;
    uint32 RunningSampleIndex;
    int WavePeriod = SamplesPerSecond;
    int BytesPerSample;
    int SecondaryBufferSize;
    real32 tSine;
    int LatencySampleCount;
};
