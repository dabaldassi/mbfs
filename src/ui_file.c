#include <linux/string.h>
#include <linux/slab.h>

#include "ui_file.h"

static struct ui_file * file_list[NB_FILES];
static const char NAMES[][128] = {"play", "playlist", "add"};

void init_ui_file(void)
{
  size_t i;
  for(i = 0; i < NB_FILES; i++) {
    file_list[i] = NULL;
  }
}

void exit_ui_file(void)
{
  size_t i;
  for(i = 0; i < NB_FILES; i++) {
    if(file_list[i]) {
      if(file_list[i]->file_name) kfree(file_list[i]->file_name);
      kfree(file_list[i]);
      file_list[i] = NULL;
    }
  }
}

bool exists_ui_file(const struct inode * inode)
{
  size_t i = 0;
  while(i < NB_FILES && file_list[i]->file_inode != inode) ++i;
  return i < NB_FILES;
}

int add_ui_file(struct inode * inode, const char * buf,size_t size)
{
  size_t i = 0;
  if(!exists_ui_file(inode)) {
    while(i < NB_FILES && !strcmp(buf, NAMES[i])) ++i;
    if(i >= NB_FILES) return 1;
    file_list[i] = kmalloc(sizeof(struct ui_file),0);
    file_list[i]->file_inode = inode;
    file_list[i]->size = size;
    file_list[i]->file_name = kmalloc(sizeof(char) * size,0);
    strcpy(file_list[i]->file_name,buf);
  }

  return 0;
}

ssize_t read_ui_file(struct inode * inode, char __user * user_buf, size_t size)
{
  return 0;
}

ssize_t write_ui_file(struct inode * inode, const char __user * user_buf, size_t size)
{
  return 0;
}
