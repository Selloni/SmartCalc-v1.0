#include "s21_string.h"

#include <check.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

START_TEST(test_s21_memchr) {
  ck_assert_str_eq(s21_memchr("Drift", 'r', 5), memchr("Drift", 'r', 5));
  ck_assert_ptr_eq(s21_memchr("angel", 'g', 2), memchr("angel", 'g', 2));
  ck_assert_ptr_eq(s21_memchr("Planet", 'l', 0), s21_NULL);

  char *s1 =
      "I used to live in my neighbor's fishpond, but the aesthetic wasn't to "
      "my taste";
  char *s2 =
      "One small action would change her life, but whether it would be for "
      "better";
  char *s3 = "Please tell me you don't work in a morgue";

  ck_assert_ptr_eq(s21_memchr(s1, 's', 0), memchr(s1, 's', 0));
  ck_assert_ptr_eq(s21_memchr(s1, 's', 2), memchr(s1, 's', 2));
  ck_assert_ptr_eq(s21_memchr(s2, 's', 69), memchr(s2, 's', 69));
  ck_assert_ptr_eq(s21_memchr(s2, 'u', 69), memchr(s2, 'u', 69));
  ck_assert_ptr_eq(s21_memchr(s3, 'u', 42), memchr(s3, 'u', 42));
  ck_assert_ptr_eq(s21_memchr(s3, 'u', 42), memchr(s3, 'u', 42));
}
END_TEST

START_TEST(test_s21_memcmp) {
  char s11[200] =
      "The beauty of the sunset was obscured by the industrial cranes";
  char s22[200] = "It was the scarcity that fueled his creativity";
  char s33[200] =
      "If my calculator had a history, it would be more embarrassing than my "
      "browser history";

  ck_assert_msg(s21_memcmp(s11, s22, 15) == memcmp(s11, s22, 15),
                "Fail: memcmp 1");
  ck_assert_msg(s21_memcmp(s33, s11, 10) == memcmp(s33, s11, 10),
                "Fail: memcmp 3");
  ck_assert_msg(s21_memcmp(s11, s22, 20) == memcmp(s11, s22, 20),
                "Fail: memcmp 4");
  ck_assert_msg(s21_memcmp(s33, s11, 9) == memcmp(s33, s11, 9),
                "Fail: memcmp 6");
}
END_TEST

START_TEST(test_s21_memcpy) {
  char s1[] = "nothing is as cautiously cuddly as a pet porcupine";
  ck_assert_str_eq(s21_memcpy(s1, "fastidious", 6),
                   "fastidg is as cautiously cuddly as a pet porcupine");
  ck_assert_ptr_eq(s21_memcpy(s1, s21_NULL, 6), s21_NULL);

  char *src1 = "Today I heard something new and unmemorable";
  int len = s21_strlen(src1);
  char dest1[100] = {0};
  char dest2[100] = {0};
  char dest3[100] = {0};
  char dest4[100] = {0};
  char dest5[100] = {0};
  char dest6[100] = {0};
  char dest7[100] = {0};
  char dest8[100] = {0};
  char dest9[100] = {0};
  char dest10[100] = {0};
  char dest11[100] = {0};
  char dest12[100] = {0};

  s21_memcpy(dest1, src1, len + 1);
  memcpy(dest2, src1, len + 1);

  s21_memcpy(dest3, src1, 5);
  memcpy(dest4, src1, 5);

  s21_memcpy(dest5, src1, 0);
  memcpy(dest6, src1, 0);

  s21_memcpy(dest7, src1, 18);
  memcpy(dest8, src1, 18);

  s21_memcpy(dest9, src1, 1);
  memcpy(dest10, src1, 1);

  s21_memcpy(dest11, src1, 7);
  memcpy(dest12, src1, 7);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest3, dest4);
  ck_assert_str_eq(dest5, dest6);
  ck_assert_str_eq(dest7, dest8);
  ck_assert_str_eq(dest9, dest10);
  ck_assert_str_eq(dest11, dest12);
}
END_TEST

START_TEST(test_s21_memmove) {
  unsigned char dest[30] = "";
  unsigned char dest_2[30] = "";
  ck_assert_str_eq(s21_memmove(dest, "I, am, never, at, home, on, Sundays!", 5),
                   memmove(dest_2, "I, am, never, at, home, on, Sundays!", 5));

  char *src1 =
      "Lets all be unique together until we realise we are all the same";
  int len = s21_strlen(src1);
  char dest1[100];
  char dest2[100];
  char dest3[100];
  char dest4[100];
  char dest5[100];
  char dest6[100];
  char dest9[100];
  char dest10[100];
  char dest11[100];
  char dest12[100];

  s21_memmove(dest1, src1, len + 1);
  memmove(dest2, src1, len + 1);

  s21_memmove(dest3, src1, 6);
  memmove(dest4, src1, 6);

  s21_memmove(dest5, src1, 0);
  memmove(dest6, src1, 0);

  s21_memmove(dest9, src1, 11);
  memmove(dest10, src1, 11);

  s21_memmove(dest11, src1, 42);
  memmove(dest12, src1, 42);

  ck_assert_msg(memcmp(dest1, dest2, len) == 0, "Fail: memmove 1");
  ck_assert_msg(memcmp(dest3, dest4, 5) == 0, "Fail: memmove 2");
  ck_assert_msg(memcmp(dest5, dest6, 0) == 0, "Fail: memmove 3");
  ck_assert_msg(memcmp(dest9, dest10, 1) == 0, "Fail: memmove 4");
  ck_assert_msg(memcmp(dest11, dest12, 1) == 0, "Fail: memmove 5");
}
END_TEST

START_TEST(test_s21_memset) {
  char sstr[] = "He was an introvert that extroverts seemed to love";
  char sstr1[] = "He was an introvert that extroverts seemed to love";
  ck_assert_str_eq(s21_memset(sstr, '$', 8), memset(sstr1, '$', 8));
  char sstr2[] = "The skeleton had skeletons of his own in the closet";
  char sstr3[] = "The skeleton had skeletons of his own in the closet";
  ck_assert_str_eq(s21_memset(sstr2, '#', 6), memset(sstr3, '#', 6));

  char buf1[10] = "";
  char buf2[10] = "";
  ck_assert_str_eq(s21_memset(buf1, 'n', 2), memset(buf2, 'n', 2));
  ck_assert_ptr_eq(s21_memset(s21_NULL, 'A', 150), s21_NULL);

  char str1[] = "Two more days and all his problems would be solved";
  char str2[] =
      "No matter how beautiful the sunset, it saddened her knowing she was one "
      "day older";
  char str3[] = "Patricia found the meaning of life in a bowl of Cheerios";
  char str4[] = "Potato wedges probably are not best for relationships!";
  char str5[] = "Somebody once told me the world is gonna roll me";
  char res1[] = "Two more days and all his problems would be solved";
  char res2[] =
      "No matter how beautiful the sunset, it saddened her knowing she was one "
      "day older";
  char res3[] = "Patricia found the meaning of life in a bowl of Cheerios";
  char res4[] = "Potato wedges probably are not best for relationships!";
  char res5[] = "Somebody once told me the world is gonna roll me";

  s21_memset(str1, '&', 5);
  s21_memset(str2, '*', 4);
  s21_memset(str3, 'i', 2);
  s21_memset(str4, 'l', 1);
  s21_memset(str5, 'o', 1);

  memset(res1, '&', 5);
  memset(res2, '*', 4);
  memset(res3, 'i', 2);
  memset(res4, 'l', 1);
  memset(res5, 'o', 1);

  ck_assert_msg(memcmp(str1, res1, sizeof(str1)) == 0, "Fail: memset 1");
  ck_assert_msg(memcmp(str2, res2, sizeof(str2)) == 0, "Fail: memset 2");
  ck_assert_msg(memcmp(str3, res3, sizeof(str3)) == 0, "Fail: memset 3");
  ck_assert_msg(memcmp(str4, res4, sizeof(str4)) == 0, "Fail: memset 4");
  ck_assert_msg(memcmp(str5, res5, sizeof(str5)) == 0, "Fail: memset 5");
}
END_TEST

START_TEST(test_s21_strcat) {
  char dest1[205] = "It's not possible to convince a monkey to give you ";
  char dest2[205] = "It's not possible to convince a monkey to give you ";
  ck_assert_str_eq(
      s21_strcat(dest1,
                 "a banana by promising it infinite bananas when they die"),
      strcat(dest2, "a banana by promising it infinite bananas when they die"));

  char str1[150] = "The llama ";
  char str2[10] = "couldnt";
  char str3[20] = "resist trying ";
  char str4[15] = "the lemonade.";
  char str5[1] = "";
  char str6[2] = " ";

  s21_strcat(str1, str5);
  ck_assert_msg(!memcmp(str1, "The llama ", 10), "Fail: strcat 1");

  s21_strcat(str1, str2);
  ck_assert_msg(!memcmp(str1, "The llama couldnt", 12), "Fail: strcat 2");

  s21_strcat(str1, str6);
  ck_assert_msg(!memcmp(str1, "The llama couldnt ", 12), "Fail: strcat 3");

  s21_strcat(str1, str3);
  ck_assert_msg(!memcmp(str1, "The llama couldnt resist trying ", 15),
                "Fail: strcat 4");

  s21_strcat(str1, str4);
  ck_assert_msg(
      !memcmp(str1, "The llama couldnt resist trying the lemonade.", 20),
      "Fail: strcat 5");

  s21_strcat(str1, str5);
  ck_assert_msg(
      !memcmp(str1, "The llama couldnt resist trying the lemonade.", 20),
      "Fail: strcat 6");
}
END_TEST

START_TEST(test_s21_strncat) {
  char dest1[55] = "Greetings from ";
  char dest2[55] = "Greetings from ";
  char source1[25] = "the real universe.";
  char source2[25] = "the real universe.";
  ck_assert_str_eq(s21_strncat(dest1, source1, 21),
                   strncat(dest2, source2, 21));

  char str1[100] = "Not all people ";
  char str2[25] = "who wander ";
  char str3[10] = "are lost.";
  char str4[1] = "";
  char str5[40] = "So long and thanks for the fish";

  s21_strncat(str1, str2, 3);
  ck_assert_msg(!memcmp(str1, "Not all people who", 15), "Fail: strncat 1");

  s21_strncat(str1, str4, 3);
  ck_assert_msg(!memcmp(str1, "Not all people ", 10), "Fail: strncat 2");

  s21_strncat(str2, str4, 1);
  ck_assert_msg(!memcmp(str2, "who wander ", 10), "Fail: strncat 3");

  s21_strncat(str5, str3, 8);
  ck_assert_msg(!memcmp(str5, "So long and thanks for the fish are lost.", 25),
                "Fail: strncat 4");

  char str_1[25] = "TEST";
  char str_5[40] = "So long and thanks for the fish";
  s21_strncat(str_5, str_1, 1);
  ck_assert_str_eq(str_5, "So long and thanks for the fishT");
}
END_TEST

START_TEST(test_s21_strchr) {
  ck_assert_str_eq(
      s21_strchr("He hated that he loved what she hated about hate", '\0'),
      strchr("He hated that he loved what she hated about hate", '\0'));
  ck_assert_str_eq(
      s21_strchr("He hated that he loved what she hated about hate", 't'),
      strchr("He hated that he loved what she hated about hate", 't'));

  char *str1 = "problEm";
  char *str2 = "tool";
  char *str3 = "crisis";
  char *str4 = "";
  char *str5 = "satellite";
  ck_assert_str_eq(s21_strchr(str1, 'E'), strchr(str1, 'E'));
  ck_assert_str_eq(s21_strchr(str3, 'i'), strchr(str3, 'i'));
  ck_assert_str_eq(s21_strchr(str5, 'a'), strchr(str5, 'a'));
  ck_assert_str_eq(s21_strchr(str1, 'E'), strchr(str1, 'E'));
  ck_assert_ptr_eq(s21_strchr(str2, 'E'), strchr(str2, 'E'));
  ck_assert_str_eq(s21_strchr(str3, 'i'), strchr(str3, 'i'));
  ck_assert_ptr_eq(s21_strchr(str4, ' '), strchr(str4, ' '));
  ck_assert_str_eq(s21_strchr(str5, 'a'), strchr(str5, 'a'));
}
END_TEST

START_TEST(test_s21_strcmp) {
  ck_assert_int_eq(s21_strcmp("umbrella", "umbrella"),
                   strcmp("umbrella", "umbrella"));
  ck_assert_int_eq(s21_strcmp("ABC", "BC"), strcmp("ABC", "BC"));
  ck_assert_int_eq(s21_strcmp("", "ab"), -'a');
  ck_assert_int_eq(s21_strcmp("\0", "abc"), -'a');
  ck_assert_int_eq(s21_strcmp("bbn", "abb"), strcmp("bbn", "abb"));
  ck_assert_int_eq(s21_strcmp("", ""), strcmp("", ""));

  char t1[] = "I would be delighted if the sea";
  char t2[] = "I would be delighted if the sea were full of cucumber juice";
  ck_assert_msg(s21_strcmp(t1, t2) == -32, "Fail: strcmp 1");

  char t3[] = "I would be delighted if the sea";
  char t4[] = "were full of cucumber juice";
  ck_assert_msg(s21_strcmp(t3, t4) == -46, "Fail: strcmp 2");

  char t5[] = "F\0BCD";
  char t6[] = "F";
  ck_assert_msg(s21_strcmp(t5, t6) == 0, "Fail: strcmp 3");

  char t7[] = "spectrum";
  char t8[] = "m";
  ck_assert_msg(s21_strcmp(t7, t8) == 6, "Fail: strcmp 4");

  char t9[] = "bridge";
  char t10[] = "rib";
  ck_assert_msg(s21_strcmp(t9, t10) == -16, "Fail: strcmp 5");
}
END_TEST

START_TEST(test_s21_strncmp) {
  ck_assert_int_eq(s21_strncmp("origin", "origin", 10000),
                   strncmp("origin", "origin", 10000));
  ck_assert_int_eq(s21_strncmp("origin", "oregin", 3),
                   strncmp("origin", "oregin", 3));
  ck_assert_int_eq(s21_strncmp("", "b", 1), strncmp("", "b", 1));

  char *t1 = "Lucifer was surprised at";
  char *t2 = "Lucifer was surprised at the amount of life at Death Valley";
  ck_assert_msg(!s21_strncmp(t1, t2, 10) && !strncmp(t1, t2, 10),
                "Fail: strncmp 1");
  ck_assert_msg(s21_strncmp(t1, t2, 48) < 0 && strncmp(t1, t2, 48) < 0,
                "Fail: strncmp 2");
  char *t3 = "";
  char *t4 = "A";
  ck_assert_msg(s21_strncmp(t3, t4, 0) == 0 && strncmp(t3, t4, 0) == 0,
                "Fail: strncmp 3");
  ck_assert_msg(s21_strncmp(t3, t4, 1) < 0 && strncmp(t3, t4, 1) < 0,
                "Fail: strncmp 4");
  char *t5 = "Please wait outside of the house";
  char *t6 = "Ple";
  ck_assert_msg(s21_strncmp(t5, t6, 5) > 0 && strncmp(t5, t6, 5) > 0,
                "Fail: strncmp 5");
  ck_assert_msg(s21_strncmp(t5, t6, 0) == 0 && strncmp(t5, t6, 0) == 0,
                "Fail: strncmp 6");
}
END_TEST

START_TEST(test_s21_strcpy) {
  char src1[] = "reluctance";
  char dest1[20] = "temperature";
  ck_assert_str_eq(s21_strcpy(dest1, src1), strcpy(dest1, src1));

  char src2[] = "solid";
  char dest2[] = "feign";
  ck_assert_str_eq(s21_strcpy(dest2, src2), strcpy(dest2, src2));

  char src3[] = "hero";
  char dest3[15];
  ck_assert_str_eq(s21_strcpy(dest3, src3), strcpy(dest3, src3));

  char s1[50] = "scenario";
  char d1[50] = "";
  s21_strcpy(d1, s1);
  ck_assert_msg(!strcmp(d1, s1), "Fail: strcpy 1");

  char s2[50] = "chocolate";
  char d2[50] = "talk";
  s21_strcpy(d2, s2);
  ck_assert_msg(!strcmp(d2, s2), "Fail: strcpy 2");

  char s3[50] = "";
  char d3[50] = "projection";
  s21_strcpy(d3, s3);
  ck_assert_msg(!strcmp(d3, s3), "Fail: strcpy 3");

  char s4[50] = "angel";
  char d4[50] = "fireplace";
  s21_strcpy(d4, s4);
  ck_assert_msg(!strcmp(d4, s4), "Fail: strcpy 4");

  char s5[50] = "culture";
  char d5[50] = "confrontation";
  s21_strcpy(d5, s5);
  ck_assert_msg(!strcmp(d5, s5), "Fail: strcpy 5");
}
END_TEST

START_TEST(test_s21_strncpy) {
  char src1[] = "soap\0exposure";
  char dst1[] = "competition";
  ck_assert_str_eq(s21_strncpy(dst1, src1, 7), strncpy(dst1, src1, 7));

  char src2[] = "12345\0006789";
  char dst2[] = "1111111111";
  ck_assert_str_eq(s21_strncpy(dst2, src2, 3), strncpy(dst2, src2, 3));

  char a[50] = "If I don't like something, I'll stay away from it";
  char b[20] = "";
  ck_assert_str_eq(s21_strncpy(b, a, 10), strncpy(b, a, 10));

  char s1[50] = "He decided to fake his disappearance to avoid jail";
  char d1[50] = "";
  s21_strncpy(d1, s1, 2);
  ck_assert_msg(!strcmp(d1, "He"), "Fail: strncpy 1");

  char s2[50] = "check";
  char d2[50] = "deserve";
  s21_strncpy(d2, s2, 0);
  ck_assert_msg(!strcmp(d2, "deserve"), "Fail: strncpy 2");

  char s3[50] = "S";
  char d3[50] = "fOMEBODY";
  s21_strncpy(d3, s3, 1);
  ck_assert_msg(!strcmp(d3, "SOMEBODY"), "Fail: strncpy 3");

  char s4[50] = "mob";
  char d4[50] = "qweius";
  s21_strncpy(d4, s4, 3);
  ck_assert_msg(!strcmp(d4, "mobius"), "Fail: strncpy 4");

  char s5[50] = "shrek";
  char d5[50] = "s";
  s21_strncpy(d5, s5, 5);
  ck_assert_msg(!strcmp(d5, "shrek"), "Fail: strncpy 5");
}
END_TEST

START_TEST(test_s21_strcspn) {
  char test1[] = "solve";
  ck_assert_int_eq(s21_strcspn("sorry", test1), strcspn("sorry", test1));
  ck_assert_int_eq(s21_strcspn("threaten\0", test1),
                   strcspn("threaten\0", test1));
  ck_assert_int_eq(s21_strcspn("\0", test1), strcspn("\0", test1));
  ck_assert_int_eq(s21_strcspn("123", test1), strcspn("123", test1));

  char *str1 = "0123456789";
  char *str2 = "9876";
  ck_assert_msg(s21_strcspn(str1, str2) == strcspn(str1, str2),
                "Fail: strcspn 1");

  char *str3 = "disappear";
  char *str4 = "";
  ck_assert_msg(s21_strcspn(str3, str4) == strcspn(str3, str4),
                "Fail: strcspn 2");

  char *str5 = "";
  char *str6 = "licence";
  ck_assert_msg(s21_strcspn(str5, str6) == strcspn(str5, str6),
                "Fail: strcspn 3");

  char *str7 = "introduce";
  char *str8 = "pleasant";
  ck_assert_msg(s21_strcspn(str7, str8) == strcspn(str7, str8),
                "Fail: strcspn 4");

  char *str9 = "drama";
  char *str10 = "ram";
  ck_assert_msg(s21_strcspn(str9, str10) == strcspn(str9, str10),
                "Fail: strcspn 5");
}
END_TEST

START_TEST(test_s21_strerror) {
  FILE *f;
  f = fopen("qwerty.txt", "r");
  if (f == NULL) {
    ck_assert_str_eq(s21_strerror(errno), strerror(errno));
  }

  ck_assert_str_eq(s21_strerror(200), strerror(200));
  ck_assert_str_eq(s21_strerror(-15), strerror(-15));

  char *str1 = s21_strerror(6);
  char *str2 = strerror(6);
  ck_assert_str_eq(str1, str2);

  char *str3 = s21_strerror(14);
  char *str4 = strerror(14);
  ck_assert_str_eq(str3, str4);

  char *str5 = s21_strerror(1444);
  char *str6 = strerror(1444);
  ck_assert_str_eq(str5, str6);

  char *str7 = s21_strerror(1);
  char *str8 = strerror(1);
  ck_assert_str_eq(str7, str8);

  char *str9 = s21_strerror(26);
  char *str10 = strerror(26);
  ck_assert_str_eq(str9, str10);
}
END_TEST

START_TEST(test_s21_strlen) {
  ck_assert_int_eq(s21_strlen("survival"), strlen("survival"));
  ck_assert_int_eq(s21_strlen("attractive\0"), strlen("attractive\0"));
  ck_assert_int_eq(s21_strlen(""), strlen(""));
  ck_assert_int_eq(s21_strlen("\0"), strlen("\0"));

  char *s1 = "revolution";
  ck_assert_msg(s21_strlen(s1) == strlen(s1), "Fail: strlen 1");

  char *s2 = "";
  ck_assert_msg(s21_strlen(s2) == strlen(s2), "Fail: strlen 2");

  char *s3 = "Having no hair made him look even hairier";
  ck_assert_msg(s21_strlen(s3) == strlen(s3), "Fail: strlen 3");

  char *s4 = "The sudden rainstorm washed crocodiles into the ocean";
  ck_assert_msg(s21_strlen(s4) == strlen(s4), "Fail: strlen 4");

  char *s5 = "He had a vague sense that trees gave birth to dinosaurs";
  ck_assert_msg(s21_strlen(s5) == strlen(s5), "Fail: strlen 5");
}
END_TEST

START_TEST(test_s21_strpbrk) {
  char test1[] = "aaaaa";
  ck_assert_str_eq(s21_strpbrk("breakfast", test1),
                   strpbrk("breakfast", test1));
  ck_assert_str_eq(s21_strpbrk("breakfast\0", test1),
                   strpbrk("breakfast\0", test1));

  char *str1 = "helluva";
  char *str2 = "hell";
  char *res1, *res2;
  res1 = s21_strpbrk(str1, str2);
  res2 = strpbrk(str1, str2);
  ck_assert_str_eq(res1, res2);

  char *str4 = "ab";
  res1 = s21_strpbrk(str1, str4);
  res2 = strpbrk(str1, str4);
  ck_assert_ptr_eq(res1, res2);

  char *str5 = "u";
  res1 = s21_strpbrk(str1, str5);
  res2 = strpbrk(str1, str5);
  ck_assert_str_eq(res1, res2);

  char *str6 = "cable";
  char *str7 = "cab";
  res1 = s21_strpbrk(str6, str7);
  res2 = strpbrk(str6, str7);
  ck_assert_str_eq(res1, res2);

  char *str8 = "Today I bought a raincoat and wore it on a sunny day";
  char *str9 = "bought";
  res1 = s21_strpbrk(str8, str9);
  res2 = s21_strpbrk(str8, str9);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_strrchr) {
  ck_assert_str_eq(s21_strrchr("bronz e", 'e'), strrchr("bronz e", 'e'));
  ck_assert_ptr_eq(s21_strrchr(s21_NULL, 'c'), s21_NULL);

  char s1[200] =
      "The hawk didn't understand why the ground squirrels didn't want to be "
      "his friend";
  char s2[100] = "blob";
  char s3[200] = "She advised him to come back at once";

  ck_assert_msg(s21_strrchr(s1, 'w') == strrchr(s1, 'w'), "Fail: strrchr 1");
  ck_assert_msg(s21_strrchr(s1, 'o') == strrchr(s1, 'o'), "Fail: strrchr 2");
  ck_assert_msg(s21_strrchr(s2, 'o') == strrchr(s2, 'o'), "Fail: strrchr 3");
  ck_assert_msg(s21_strrchr(s3, ' ') == strrchr(s3, ' '), "Fail: strrchr 4");
  ck_assert_msg(s21_strrchr(s3, 's') == strrchr(s3, 's'), "Fail: strrchr 5");
}
END_TEST

START_TEST(test_s21_strspn) {
  ck_assert_int_eq(s21_strspn("garlic", "grl"), strspn("garlic", "grl"));
  ck_assert_int_eq(s21_strspn("garlic", "qwy"), strspn("garlic", "qwy"));

  char s1[] = "Situps are a terrible way to end your day";
  char s2[] = "terra";
  char s3[] = "";

  ck_assert_msg(s21_strspn(s1, s2) == strspn(s1, s2), "Fail: strspn 1");
  ck_assert_msg(s21_strspn(s3, s2) == strspn(s3, s2), "Fail: strspn 2");
  ck_assert_msg(s21_strspn(s2, s3) == strspn(s2, s3), "Fail: strspn 3");
  ck_assert_msg(s21_strspn(s1, s3) == strspn(s1, s3), "Fail: strspn 4");
  ck_assert_msg(s21_strspn(s3, s1) == strspn(s3, s1), "Fail: strspn 5");
}
END_TEST

START_TEST(test_s21_strstr) {
  ck_assert_str_eq(s21_strstr("bloody", "lo"), strstr("bloody", "lo"));
  ck_assert_ptr_eq(s21_strstr("bloody", "tar"), s21_NULL);
  ck_assert_ptr_eq(s21_strstr(s21_NULL, "ter"), s21_NULL);
  ck_assert_ptr_eq(s21_strstr(s21_NULL, s21_NULL), s21_NULL);
  ck_assert_ptr_eq(s21_strstr("stain", "stainless"), s21_NULL);
  ck_assert_str_eq(s21_strstr("anticipation", "anticipation"),
                   strstr("anticipation", "anticipation"));

  char *s1 = "The memory we used to share is no longer coherent";
  char *s2 = "mermaid";
  char *s3 = "";

  ck_assert_msg(s21_strstr(s1, s2) == strstr(s1, s2), "Fail: strstr 1");
  ck_assert_msg(s21_strstr(s1, s3) == strstr(s1, s3), "Fail: strstr 2");
  ck_assert_msg(s21_strstr(s3, s2) == strstr(s3, s2), "Fail: strstr 3");
  ck_assert_msg(s21_strstr(s2, s3) == strstr(s2, s3), "Fail: strstr 4");
  ck_assert_msg(s21_strstr(s3, s1) == strstr(s3, s1), "Fail: strstr 5");
}
END_TEST

START_TEST(test_s21_strtok) {
  char src_str1[] = "I can't believe this is the eighth time";
  char src_str2[] = "I can't believe this is the eighth time";
  const char *delim = " ";

  char *my_token = s21_strtok(src_str1, delim);
  char *orig_token = strtok(src_str2, delim);

  while (my_token && orig_token) {
    ck_assert_str_eq(my_token, orig_token);
    my_token = s21_strtok(s21_NULL, delim);
    orig_token = strtok(s21_NULL, delim);
  }

  char src_str3[] = "";
  const char *delim3 = " bbbbb";

  my_token = s21_strtok(src_str3, delim3);
  ck_assert_ptr_eq(my_token, s21_NULL);

  char *src_str4 = s21_NULL;
  const char *delim4 = " bbbb";

  my_token = s21_strtok(src_str4, delim4);
  ck_assert_ptr_eq(my_token, s21_NULL);

  char test1[50] = "The,stranger,officiates,the,meal";
  char test2[50] = "The,stranger,officiates,the,meal";
  char delim1[10] = "123,";
  char *orig1, *copy1;
  orig1 = strtok(test1, delim1);
  copy1 = s21_strtok(test2, delim1);
  char orig_res1[1000] = {0};
  char copy_res1[1000] = {0};
  while (orig1 != NULL) {
    strcat(orig_res1, orig1);
    orig1 = strtok(NULL, delim1);
  }
  while (copy1 != NULL) {
    strcat(copy_res1, copy1);
    copy1 = s21_strtok(NULL, delim1);
  }
  ck_assert_str_eq(orig_res1, copy_res1);

  char str[] =
      "No matter how beautiful the sunset, it saddened her knowing she was one "
      "day older";
  char *tok1 = s21_strtok(str, "-");
  char *tok2 = strtok(str, "-");
  char *tok3 = s21_strtok(str, "");
  char *tok4 = strtok(str, "");
  char *tok5 = s21_strtok(str, "su");
  char *tok6 = strtok(str, "su");
  char *tok7 = s21_strtok(str, "No");
  char *tok8 = strtok(str, "No");
  char *tok9 = s21_strtok(str, ",");
  char *tok10 = strtok(str, ",");

  ck_assert_msg(!strcmp(tok1, tok2), "Fail: strtok 1");
  ck_assert_msg(!strcmp(tok3, tok4), "Fail: strtok 2");
  ck_assert_msg(!strcmp(tok5, tok6), "Fail: strtok 3");
  ck_assert_msg(!strcmp(tok7, tok8), "Fail: strtok 4");
  ck_assert_msg(!strcmp(tok9, tok10), "Fail: strtok 5");
}
END_TEST

START_TEST(test_s21_to_upper) {
  char *a = "test";
  a = s21_to_upper(a);
  ck_assert_str_eq(a, "TEST");
  free(a);

  char *b = "tEsT";
  b = s21_to_upper(b);
  ck_assert_str_eq(b, "TEST");
  free(b);

  char *c = "TEST";
  c = s21_to_upper(c);
  ck_assert_str_eq(c, "TEST");
  free(c);

  char *d = "";
  d = s21_to_upper(d);
  ck_assert_str_eq(d, "");
  free(d);

  char *e = s21_NULL;
  e = s21_to_upper(e);
  ck_assert_ptr_eq(e, s21_NULL);
  free(e);

  char *s1 = "";
  char *s2 = "The bug was having an excellent day until he hit the windshield.";
  char *s3 =
      "ShIt Is StRaIgHt Up DaNgErOuS, aNd I'm GeTtInG mY hArSh On AbOuT iT.";
  char *s4 =
      "yEaH!! fUcK yEaH mAn, So MyStErIoUs. I'm NeVeR bEiNg GeTtInG cEaSeD";
  char *s5 = "what";

  char *r1 = s21_to_upper(s1);
  char *r2 = s21_to_upper(s2);
  char *r3 = s21_to_upper(s3);
  char *r4 = s21_to_upper(s4);
  char *r5 = s21_to_upper(s5);

  ck_assert_str_eq(r1, "");
  ck_assert_str_eq(
      r2, "THE BUG WAS HAVING AN EXCELLENT DAY UNTIL HE HIT THE WINDSHIELD.");
  ck_assert_str_eq(
      r3,
      "SHIT IS STRAIGHT UP DANGEROUS, AND I'M GETTING MY HARSH ON ABOUT IT.");
  ck_assert_str_eq(
      r4,
      "YEAH!! FUCK YEAH MAN, SO MYSTERIOUS. I'M NEVER BEING GETTING CEASED");
  ck_assert_str_eq(r5, "WHAT");

  free(r1);
  free(r2);
  free(r3);
  free(r4);
  free(r5);
}
END_TEST

START_TEST(test_s21_to_lower) {
  char *a = "test";
  a = s21_to_lower(a);
  ck_assert_str_eq(a, "test");
  free(a);

  char *b = "TeSt";
  b = s21_to_lower(b);
  ck_assert_str_eq(b, "test");
  free(b);

  char *c = "TEST";
  c = s21_to_lower(c);
  ck_assert_str_eq(c, "test");
  free(c);

  char *d = "";
  d = s21_to_lower(d);
  ck_assert_str_eq(d, "");
  free(d);

  char *e = s21_NULL;
  e = s21_to_lower(e);
  ck_assert_ptr_eq(e, s21_NULL);
  free(e);

  char s1[] = "JUST STAY IN THE PILE AND KEEP MAKING EVERYONE";
  char s2[] = "HoNk hOnK HoNk hOnK HoNk hOnK HoNk";
  char s3[] = "It Is Generally Not Regarded As One Of The More";
  char s4[] = "i sent you the money i got all the fraymotifs";
  char s5[] = "what";

  char *r1 = s21_to_lower(s1);
  char *r2 = s21_to_lower(s2);
  char *r3 = s21_to_lower(s3);
  char *r4 = s21_to_lower(s4);
  char *r5 = s21_to_lower(s5);

  ck_assert_msg(!strcmp(r1, "just stay in the pile and keep making everyone"),
                "1st to_lower test failed");
  ck_assert_msg(!strcmp(r2, "honk honk honk honk honk honk honk"),
                "2nd to_lower test failed");
  ck_assert_msg(!strcmp(r3, "it is generally not regarded as one of the more"),
                "3rd to_lower test failed");
  ck_assert_msg(!strcmp(r4, "i sent you the money i got all the fraymotifs"),
                "4rth to_lower test failed");
  ck_assert_msg(!strcmp(r5, "what"), "5th to_lower test failed");

  free(r1);
  free(r2);
  free(r3);
  free(r4);
  free(r5);
}
END_TEST

START_TEST(test_s21_insert) {
  char *src1 = "test";
  char *str1 = "123";
  src1 = s21_insert(src1, str1, 1);
  ck_assert_str_eq(src1, "t123est");
  free(src1);

  char *src2 = "test test";
  char *str2 = "123";
  src2 = s21_insert(src2, str2, 4);
  ck_assert_str_eq(src2, "test123 test");
  free(src2);

  char *src3 = "";
  char *str3 = "test test";
  src3 = s21_insert(src3, str3, 0);
  ck_assert_str_eq(src3, "test test");
  free(src3);

  char *src4 = s21_NULL;
  char *str4 = s21_NULL;
  src4 = s21_insert(src4, str4, 4);
  ;
  ck_assert_ptr_eq(src4, s21_NULL);
  free(src4);

  char *s1 = "split";
  char *s2 = "insert ";
  char *s3 = " life ";
  char *s4 = "is";
  char *s5 = "brick";
  char *res1 = s21_insert(s1, " ", 3);
  char *res2 = s21_insert(s5, s3, 5);
  char *res3 = s21_insert(s3, s5, 0);
  char *res4 = s21_insert(s5, s4, 5);
  char *res5 = s21_insert(s2, s1, 4);

  ck_assert_str_eq(res1, "spl it");
  ck_assert_str_eq(res2, "brick life ");
  ck_assert_str_eq(res3, "brick life ");
  ck_assert_str_eq(res4, "brickis");
  ck_assert_str_eq(res5, "insesplitrt ");

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
}
END_TEST

START_TEST(test_s21_trim) {
  char *src1 = "123test123test123";
  char *trim_chars1 = "123";
  src1 = s21_trim(src1, trim_chars1);
  ck_assert_str_eq(src1, "test123test");
  free(src1);

  char *src2 = "420test420";
  char *trim_chars2 = "420";
  src2 = s21_trim(src2, trim_chars2);
  ck_assert_str_eq(src2, "test");
  free(src2);

  char *src3 = "240test420";
  char *trim_chars3 = "420";
  src3 = s21_trim(src3, trim_chars3);
  ck_assert_str_eq(src3, "test");
  free(src3);

  char *src4 = "024test420 test402";
  char *trim_chars4 = "420";
  src4 = s21_trim(src4, trim_chars4);
  ck_assert_str_eq(src4, "test420 test");
  free(src4);

  char *src5 = "";
  char *trim_chars5 = "420";
  src5 = s21_trim(src5, trim_chars5);
  ck_assert_str_eq(src5, "");
  free(src5);

  char *s1 = "test";
  char *s2 = "";
  char *s3 = "t";
  char *s4 = "te";
  char *s5 = "tes";
  char *s6 = "test";
  char *s7 = NULL;
  char *r1 = s21_trim(s1, s2);
  char *r2 = s21_trim(s1, s3);
  char *r3 = s21_trim(s1, s4);
  char *r4 = s21_trim(s1, s5);
  char *r5 = s21_trim(s1, s6);
  char *r6 = s21_trim(s1, s7);
  ck_assert_msg(!strcmp(r1, "test"), "1st trim test failed");
  ck_assert_msg(!strcmp(r2, "es"), "2nd trim test failed");
  ck_assert_msg(!strcmp(r3, "s"), "3rd trim test failed");
  ck_assert_msg(!strcmp(r4, ""), "4rth trim test failed");
  ck_assert_msg(!strcmp(r5, ""), "5th trim test failed");
  ck_assert_msg(!strcmp(r6, "test"), "6th trim test failed");
  free(r1);
  free(r2);
  free(r3);
  free(r4);
  free(r5);
  free(r6);
}
END_TEST

START_TEST(test_s21_sscanf) {
  long a;
  int b, ib, ib2;
  unsigned int ob;
  unsigned int ob2;
  unsigned int ka;
  unsigned int ki;
  long a1;
  int b1;
  unsigned int b12, b22;
  int n12, n22, n31, n32, n41, n42, n1, n2;
  float f = 2;
  char s[20];
  float f1 = 2;
  double f11 = 2;
  double f12 = 2;
  char s1[20];
  char c[20];
  int si = -789;
  char sinok[1], bobik[1], rt[1];

  ck_assert_int_eq(s21_sscanf(c, "%16d", &si), sscanf(c, "%16d", &si));
  ck_assert_int_eq(s21_sscanf(c, "%016d", &si), sscanf(c, "%016d", &si));

  ck_assert_int_eq(s21_sscanf("256 ", "%ld%n", &a, &n12),
                   sscanf("256 ", "%ld%n", &a1, &n22));
  ck_assert_int_eq(s21_sscanf(" 23.2345", "%f%n", &f, &n2),
                   sscanf(" 23.2345", "%f%n", &f1, &n1));
  ck_assert_int_eq(s21_sscanf("890", "%d%n", &b, &n2),
                   sscanf("890", "%d%n", &b1, &n1));
  ck_assert_int_eq(s21_sscanf("gcs", "%s", s), sscanf("gcs", "%3s", s1));
  ck_assert_int_eq(s21_sscanf("10", "%x%n", &ki, &n1),
                   sscanf("10", "%x%n", &ka, &n2));
  ck_assert_int_eq(
      s21_sscanf("564 3774", "%u%n%o%n%i", &b12, &n31, &ob, &n41, &ib),
      sscanf("564 3774", "%u%n%o%n%i", &b22, &n32, &ob2, &n42, &ib2));
  ck_assert_int_eq(s21_sscanf("g", "%c", bobik), sscanf("g", "%c", sinok));
  ck_assert_int_eq(s21_sscanf("%%", "%%", rt), sscanf("%%", "%%"));
  ck_assert_int_eq(s21_sscanf("1.23e-03", "%lf", &f11),
                   sscanf("1.23e-03", "%lf", &f12));
}
END_TEST

START_TEST(test_s21_sprintf) {
  char s21_str[100];
  char str[100];

  s21_sprintf(s21_str, "check basic text");
  sprintf(str, "check basic text");
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check number %d", 5);
  sprintf(str, "check number %d", 5);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check string %s string", "check");
  sprintf(str, "check string %s string", "check");
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check unsigned %u here", 420);
  sprintf(str, "check unsigned %u here", 420);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check negative number %d negative", -420);
  sprintf(str, "check negative number %d negative", -420);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check float number %f float", 420.69);
  sprintf(str, "check float number %f float", 420.69);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check negative float number %f float", -420.69);
  sprintf(str, "check negative float number %f float", -420.69);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check character %c character", '*');
  sprintf(str, "check character %c character", '*');
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check character precision %3c precision", '*');
  sprintf(str, "check character precision %3c precision", '*');
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check integer precision %3i precision", 5);
  sprintf(str, "check integer precision %3i precision", 5);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check integer flag %+i flag", 5);
  sprintf(str, "check integer flag %+i flag", 5);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check float flag %+.4f flag", 111.111);
  sprintf(str, "check float flag %+.4f flag", 111.111);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check float %-13.4f check", 19.87);
  sprintf(str, "check float %-13.4f check", 19.87);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check integer precision %.5i int", 5);
  sprintf(str, "check integer precision %.5i int", 5);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check space integer % 5i space", 5);
  sprintf(str, "check space integer % 5i space", 5);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "integer asterisk %*d asterisk", 6, 2);
  sprintf(str, "integer asterisk %*d asterisk", 6, 2);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check exp %e exp", 0.1789);
  sprintf(str, "check exp %e exp", 0.1789);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check big exp %E big", 0.4784);
  sprintf(str, "check big exp %E big", 0.4784);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check hex %x hex", 1234);
  sprintf(str, "check hex %x hex", 1234);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check flag hex %#x flag hex", 1234);
  sprintf(str, "check flag hex %#x flag hex", 1234);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check hex zero %x zero", 0);
  sprintf(str, "check hex zero %x zero", 0);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check big hex %X big hex", 1234);
  sprintf(str, "check big hex %X big hex", 1234);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check oct %o oct", 1234);
  sprintf(str, "check oct %o oct", 1234);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check oct zero %o zero", 0);
  sprintf(str, "check oct zero %o zero", 0);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check oct flag %#o flag", 1234);
  sprintf(str, "check oct flag %#o flag", 1234);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check oct precision %*o", -7, 0);
  sprintf(str, "check oct precision %*o", -7, 0);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check %010d", 50);
  sprintf(str, "check %010d", 50);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check tochka flag %.*f tochka", 1, 68.897);
  sprintf(str, "check tochka flag %.*f tochka", 1, 68.897);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check long int %d long", 97978558);
  sprintf(str, "check long int %d long", 97978558);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "long long integer %ld", 98989875656);
  sprintf(str, "long long integer %ld", 98989875656);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "short int %hd short", 777778965);
  sprintf(str, "short int %hd short", 777778965);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "long double %Lf double", (long double)76969.967845);
  sprintf(str, "long double %Lf double", (long double)76969.967845);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "long double %.Lf double tochka",
              (long double)76969.967845);
  sprintf(str, "long double %.Lf double tochka", (long double)76969.967845);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "tochka float %.10f tochka", 445.00049);
  sprintf(str, "tochka float %.10f tochka", 445.00049);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "exp point %e", 8.9);
  sprintf(str, "exp point %e", 8.9);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check short usigned %hu short", 26);
  sprintf(str, "check short usigned %hu short", 26);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check long unsigned int %lu long usigned",
              (long unsigned int)16969696969);
  sprintf(str, "check long unsigned int %lu long usigned",
          (long unsigned int)16969696969);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check long exp %Le long exp", (long double)16.8);
  sprintf(str, "check long exp %Le long exp", (long double)16.8);
  ck_assert_str_eq(s21_str, str);

  s21_sprintf(s21_str, "check percent %% percent");
  sprintf(str, "check percent %% percent");
  ck_assert_str_eq(s21_str, str);

  char str1[100];
  char str2[100];
  s21_sprintf(str1, "[%LG][%g][%G][%Lg][%.5g]", (long double)0.000005, 41.1341,
              848.9000, (long double)0.0843, 0.0005),
      sprintf(str2, "[%LG][%g][%G][%Lg][%.5g]", (long double)0.000005, 41.1341,
              848.9000, (long double)0.0843, 0.0005);
  ck_assert_str_eq(str1, str2);

  char str3[100];
  char str4[100];
  ck_assert_int_eq(
      s21_sprintf(str3, "[%e][%Lf][%Lf][%Le]", 123.123, (long double)848181,
                  (long double)0.00000001, (long double)1111111.11),
      sprintf(str4, "[%e][%Lf][%Lf][%Le]", 123.123, (long double)848181,
              (long double)0.00000001, (long double)1111111.11));
  ck_assert_str_eq(str3, str4);

  char str5[100];
  char str6[100];
  ck_assert_int_eq(s21_sprintf(str5, "[%#.10x][%#15.1o][%25.10s]", 1234, 4567,
                               "blahblahBLAHBLAH"),
                   sprintf(str6, "[%#.10x][%#15.1o][%25.10s]", 1234, 4567,
                           "blahblahBLAHBLAH"));
  ck_assert_str_eq(str5, str6);

  char str7[100];
  char str8[100];

  ck_assert_int_eq(
      s21_sprintf(str7, "[%5.3e][%3.2e][%lf]", 0.000111, 111.555, 1.999),
      sprintf(str8, "[%5.3e][%3.2e][%lf]", 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str7, str8);

  char str9[100];
  char str10[100];
  void *p1 = (void *)43252342;
  ck_assert_int_eq(sprintf(str9, "[%#24.e][%-15.20i][%20p][%020u]",
                           43253242.4342, 4567899, p1, 43252342u),
                   s21_sprintf(str10, "[%#24.e][%-15.20i][%20p][%020u]",
                               43253242.4342, 4567899, p1, 43252342u));
  ck_assert_str_eq(str9, str10);

  char str11[1000];
  char str12[1000];
  ck_assert_int_eq(
      sprintf(str11, "[%2c][%+4.2d][%+5.4i][%+10.2f][%55.55s][%1.1u]", 'f', 21,
              42, 666.666,
              "Lucifer was surprised at the amount of life at Death Valley",
              11),
      s21_sprintf(str12, "[%2.1c][%+4.2d][%+5.4i][%+10.2f][%55.55s][%1.1u]",
                  'f', 21, 42, 666.666,
                  "Lucifer was surprised at the amount of life at Death Valley",
                  11));
  ck_assert_str_eq(str11, str12);

  char str13[1000];
  char str14[1000];
  short h1 = 34;
  long l1 = 2353423523424;
  ck_assert_int_eq(
      sprintf(
          str13,
          "[%+50.i][%-10.20i][%10.i][%012i][%*.*i][%-10.*i][%+10.1li][%*.25hi]",
          34567, 225, 5230, 125, 10, 5, 456, 10, 377, l1, 12, h1),
      s21_sprintf(
          str14,
          "[%+50.i][%-10.20i][%10.i][%012i][%*.*i][%-10.*i][%+10.1li][%*.25hi]",
          34567, 225, 5230, 125, 10, 5, 456, 10, 377, l1, 12, h1));
  ck_assert_str_eq(str13, str14);

  char str15[1000] = "";
  char str16[1000] = "";
  wchar_t s[10] = {'m', 'o', 'r', 'b', 'i', 'u', 's'};
  int r31 = sprintf(str15, "%s/%13s/%-12s/%9.s/%17.2s/%14.*s/%*.*s/%*s/%13.3ls",
                    "morbin", "time", "LOOOL", "HOOOONK", "stop", 7, "AZERTY",
                    15, 4, "AAAAAAAA", 10, "BBBBBB", s);
  int r32 =
      s21_sprintf(str16, "%s/%13s/%-12s/%9.s/%17.2s/%14.*s/%*.*s/%*s/%13.3ls",
                  "morbin", "time", "LOOOL", "HOOOONK", "stop", 7, "AZERTY", 15,
                  4, "AAAAAAAA", 10, "BBBBBB", s);
  ck_assert_str_eq(str15, str16);
  ck_assert_int_eq(r31, r32);

  char str17[1000];
  char str18[1000];
  wchar_t c1 = 'Q', c2 = 'R';
  int r17 = sprintf(str17, "%10c/%-10c/%25c/%-30c/%25c/%*c/%2c/%*c/%lc/%-50lc",
                    'b', 'g', 'l', 'F', 'X', 4, 'S', 'T', 17, 'y', c1, c2);
  int r18 =
      s21_sprintf(str18, "%10c/%-10c/%25c/%-30c/%25c/%*c/%2c/%*c/%lc/%-50lc",
                  'b', 'g', 'l', 'F', 'X', 4, 'S', 'T', 17, 'y', c1, c2);
  ck_assert_str_eq(str17, str18);
  ck_assert_int_eq(r17, r18);
  char str21[1000];
  char str22[1000];
  int r21 = sprintf(str21,
                    "[%+-10.5f][%+10.2f][%15.16f][%+*.10f][%*.16f][%-10.*f][%"
                    "25.*f][%25.f][%#+10.f][%*.*f]",
                    2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10,
                    3456789123.43245, 2, 12345.6788, 1, 34.4325432,
                    4325678.43242, 34567.2345432, 10, 2, 34567.43244);
  int r22 = s21_sprintf(str22,
                        "[%+-10.5f][%+10.2f][%15.16f][%+*.10f][%*.16f][%-10.*f]"
                        "[%25.*f][%25.f][%#+10.f][%*.*f]",
                        2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10,
                        3456789123.43245, 2, 12345.6788, 1, 34.4325432,
                        4325678.43242, 34567.2345432, 10, 2, 34567.43244);
  ck_assert_str_eq(str21, str22);
  ck_assert_int_eq(r21, r22);
}
END_TEST

Suite *s21_string_test_suite() {
  Suite *s = suite_create("s21_string_test_suite");

  TCase *s_strtok = tcase_create("strtok");
  suite_add_tcase(s, s_strtok);
  tcase_add_test(s_strtok, test_s21_strtok);

  TCase *s_memchr = tcase_create("s_memchr");
  suite_add_tcase(s, s_memchr);
  tcase_add_test(s_memchr, test_s21_memchr);

  TCase *s_strstr = tcase_create("s_strstr");
  suite_add_tcase(s, s_strstr);
  tcase_add_test(s_strstr, test_s21_strstr);

  TCase *s_strspn = tcase_create("s_strspn");
  suite_add_tcase(s, s_strspn);
  tcase_add_test(s_strspn, test_s21_strspn);

  TCase *s_strrchr = tcase_create("s_strrchr");
  suite_add_tcase(s, s_strrchr);
  tcase_add_test(s_strrchr, test_s21_strrchr);

  TCase *s_memset = tcase_create("s_memset");
  suite_add_tcase(s, s_memset);
  tcase_add_test(s_memset, test_s21_memset);

  TCase *s_strcat = tcase_create("s_strcat");
  suite_add_tcase(s, s_strcat);
  tcase_add_test(s_strcat, test_s21_strcat);

  TCase *s_strncat = tcase_create("s_strncat");
  suite_add_tcase(s, s_strncat);
  tcase_add_test(s_strncat, test_s21_strncat);

  TCase *s_strchr = tcase_create("s_strchr");
  suite_add_tcase(s, s_strchr);
  tcase_add_test(s_strchr, test_s21_strchr);

  TCase *s_strncmp = tcase_create("s_strncmp");
  suite_add_tcase(s, s_strncmp);
  tcase_add_test(s_strncmp, test_s21_strncmp);

  TCase *s_strcmp = tcase_create("s_strcmp");
  suite_add_tcase(s, s_strcmp);
  tcase_add_test(s_strcmp, test_s21_strcmp);

  TCase *s_memcmp = tcase_create("s_memcmp");
  suite_add_tcase(s, s_memcmp);
  tcase_add_test(s_memcmp, test_s21_memcmp);

  TCase *s_strncpy = tcase_create("s_strncpy");
  suite_add_tcase(s, s_strncpy);
  tcase_add_test(s_strncpy, test_s21_strncpy);

  TCase *s_strcpy = tcase_create("s_strcpy");
  suite_add_tcase(s, s_strcpy);
  tcase_add_test(s_strcpy, test_s21_strcpy);

  TCase *s_strlen = tcase_create("s_strlen");
  suite_add_tcase(s, s_strlen);
  tcase_add_test(s_strlen, test_s21_strlen);

  TCase *s_memcpy = tcase_create("s_memcpy");
  suite_add_tcase(s, s_memcpy);
  tcase_add_test(s_memcpy, test_s21_memcpy);

  TCase *s_memmove = tcase_create("s_memmove");
  suite_add_tcase(s, s_memmove);
  tcase_add_test(s_memmove, test_s21_memmove);

  TCase *s_strcspn = tcase_create("s_strcspn");
  suite_add_tcase(s, s_strcspn);
  tcase_add_test(s_strcspn, test_s21_strcspn);

  TCase *s_strpbrk = tcase_create("s_strpbrk");
  suite_add_tcase(s, s_strpbrk);
  tcase_add_test(s_strpbrk, test_s21_strpbrk);

  TCase *s_sscanf = tcase_create("s_sscanf");
  suite_add_tcase(s, s_sscanf);
  tcase_add_test(s_sscanf, test_s21_sscanf);

  TCase *s_sprintf = tcase_create("s_sprintf");
  suite_add_tcase(s, s_sprintf);
  tcase_add_test(s_sprintf, test_s21_sprintf);

  TCase *s_strerror = tcase_create("s_strerror");
  suite_add_tcase(s, s_strerror);
  tcase_add_test(s_strerror, test_s21_strerror);

  TCase *s_to_upper = tcase_create("s_to_upper");
  suite_add_tcase(s, s_to_upper);
  tcase_add_test(s_to_upper, test_s21_to_upper);

  TCase *s_to_lower = tcase_create("s_to_lower");
  suite_add_tcase(s, s_to_lower);
  tcase_add_test(s_to_lower, test_s21_to_lower);

  TCase *s_insert = tcase_create("s_insert");
  suite_add_tcase(s, s_insert);
  tcase_add_test(s_insert, test_s21_insert);

  TCase *s_trim = tcase_create("s_trim");
  suite_add_tcase(s, s_trim);
  tcase_add_test(s_trim, test_s21_trim);

  return s;
}

int main() {
  int no_failed = 0;

  Suite *s = s21_string_test_suite();

  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
