set(TARGET_PREFIX ch06-)


add_library(${TARGET_PREFIX}ch06_sample_code OBJECT)
target_sources(${TARGET_PREFIX}ch06_sample_code PRIVATE
    binio.c
    csvburst.c
    csvwrite.c
    getcols.c
    getwords.c
    ieee754.c
    inifetch.c
    time_t.c)
