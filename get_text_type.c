
//앞 문자를 기준으로 타입 확인
//- 일단 앞 문자를 기준으로 타입 확인은 아래 4개인지 판단하고, 타입을 반환하는 함수
    // - 텍스쳐 방향
    // - 천장
    // - 바닥
    // - 지도

#define TRUE    1
#define FALSE   0

enum e_text_type
{
    TEXTURE_NO = 10,
    TEXTURE_SO,
    TEXTURE_WE,
    TEXTURE_EA,
    FLOOR = 20,
    CEILLING,
    MAP_CHARACTER = 30
};

#include <stdbool.h>

static int is_mapchar_type(char *line);
static int is_floor_or_ceiling_type(char *line);
static int extract_first_info_textlen(char *line);
static int is_texture_type(char *line);
int     get_text_type(int mapfd);
bool    is_space(char c);

bool    is_space(char c) // 스페이스 문자 기준 다시 확인필요!
{
    return (c == '\t' || c == ' ');
}

int get_text_type(int mapfd)
{
    char    *line;
    int     type;

    line = get_next_line(mapfd);
    if (!line)
        return (0);
    type = is_texture_type(line);
    if (type == 0)
        type = is_floor_or_ceiling_type(line);
    if (type == 0)
        type = is_mapchar_type(line);
    // FREE
    free(line);
    return (type);
}

static int    extract_first_info_textlen(char *line)
{
    // pos = 1 == First Position
    int     len;

    len = 0;
    while (line[len] && is_space(line[len]) == FALSE)
        len++;
    return (len);
}

static int is_mapchar_type(char *line)
{
    if (*line == ' ' || *line == '0' || *line == '1' || \
        *line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
        return (MAP_CHARACTER);
    return (0);
}

static int is_floor_or_ceiling_type(char *line)
{
    int info_len;

    info_len = extract_first_info_textlen(line);
    if (ft_strncmp("F", line, info_len) == 0)
        return (FLOOR);
    if (ft_strncmp("C", line, info_len) == 0)
        return (CEILLING);
    return (0);
}

static int is_texture_type(char *line)
{
    int info_len;

    info_len = extract_first_info_textlen(line);
    if (ft_strncmp("NO", line, info_len) == 0)
        return (TEXTURE_NO);
    if (ft_strncmp("SO", line, info_len) == 0)
        return (TEXTURE_SO);
    if (ft_strncmp("WE", line, info_len) == 0)
        return (TEXTURE_WE);
    if (ft_strncmp("EA", line, info_len) == 0)
        return (TEXTURE_EA);
    return (0);
}
