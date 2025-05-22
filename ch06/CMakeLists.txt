
add_library(ch06_sample_code OBJECT)
target_sources(ch06_sample_code PRIVATE
    binio.c
    csvburst.c
    csvwrite.c
    getcols.c
    getwords.c
    ieee754.c
    inifetch.c
    time_t.c)
