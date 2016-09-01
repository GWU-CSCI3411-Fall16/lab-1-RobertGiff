#include <stdio.h>

char *titles[]  = {"Freebird", "YMCA", "Sandstorm"};
char *artists[] = {"Lynard Skynard", "Village People", "Darude"};

struct song_t {
	char *title;
	char *artist;
};

struct node_t {
	struct song_t *song;
	struct node_t *next;
};

struct playlist_t {
	char *name;
	struct node_t *head;
};

void
print_list(struct playlist_t *pl)
{
	struct node_t *cur = pl->head;

	while(cur != NULL) {
		printf("%s by %s\n", cur->song->title, cur->song->artist);
		cur = cur->next;
	}
}

int
main(void)
{

	struct song_t freebird, ymca, sandstorm;
	struct playlist_t pl1, pl2;
	struct node_t pl1_s1, pl1_s2, pl1_s3;
	struct node_t pl2_s1, pl2_s2, pl2_s3;

	freebird.title = titles[0];
	freebird.artist = artists[0];
	ymca.title = titles[1];
	ymca.artist = artists[1];
	sandstorm.title = titles[2];
	sandstorm.artist = artists[2];

	/* Set up pl1 */
	pl1.name = "70's";
	pl1.head = &pl1_s1;
	pl1_s1.song = &freebird;
	pl1_s2.song = &ymca;
	pl1_s1.next = &pl1_s2;
	pl1_s2.next = NULL;

	/* Set up pl2 */
	pl2.name = "90's";

	print_list(&pl1);

	return 0;
}
