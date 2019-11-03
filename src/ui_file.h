#ifndef UI_FILE_H
#define UI_FILE_H

#define NB_FILES 1

typedef enum {PLAY, PLAYLIST, ADD} Control;

struct ui_file
{
  struct inode * file_inode;
  char         * file_name;
  size_t         size;
};

void init_ui_file(void);
void exit_ui_file(void);
bool exists_ui_file(const struct inode * inode);

int add_ui_file(struct inode * inode,const char * buf, size_t size);

ssize_t read_ui_file(struct inode * inode, char __user * user_buf, size_t count);
ssize_t write_ui_file(struct inode * inode, const char __user * user_buf, size_t count);

#endif
