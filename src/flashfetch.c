#include "fastfetch.h"

#include "modules/modules.h"

int main(void)
{
    ffInitInstance(); //This also applies default configuration to instance.config

    //Modify instance.config here
    FFOptionsModules* const options = &instance.config.modules;

    // ffPrepareCPUUsage();
    // ffPreparePublicIp(&options->publicIP);
    // ffPrepareWeather(&options->weather);

    //Does things like starting detection threads, disabling line wrap, etc
    ffStart();

    //Printing
    void* const modules[] = {
        &options->title,
        &options->separator,
        &options->host,
        &options->cpu,
        &options->os,
        &options->bios,
        &options->kernel,
        &options->terminal,
        &options->shell,
        &options->packages,
        &options->processes,
        &options->wmTheme,
        &options->version,
        &options->cursor,
        &options->locale,
        &options->uptime,
        &options->dateTime,
    };

    for (size_t i = 0; i < sizeof(modules) / sizeof(modules[0]); i++)
        ((const FFModuleBaseInfo*) modules[i])->printModule(modules[i]);

    ffFinish();
    ffDestroyInstance();
    return 0;
}
