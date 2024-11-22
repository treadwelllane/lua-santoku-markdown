#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "markdown.h"
#include "html.h"
#include "buffer.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_UNIT 64

static inline int to_html (lua_State *L)
{
  lua_settop(L, 1);
  size_t size;
  const char *s = luaL_checklstring(L, 1, &size);

	struct buf *ob;

	struct sd_callbacks callbacks;
	struct html_renderopt options;
	struct sd_markdown *markdown;

	ob = bufnew(OUTPUT_UNIT);
	sdhtml_renderer(&callbacks, &options, 0);
	markdown = sd_markdown_new(0, 16, &callbacks, &options);
	sd_markdown_render(ob, (uint8_t *) s, size, markdown);
	sd_markdown_free(markdown);

  lua_pushlstring(L, (char *) ob->data, ob->size);;
	bufrelease(ob);
  return 1;
}

static luaL_Reg fns[] =
{
  { "to_html", to_html },
  { NULL, NULL }
};

int luaopen_santoku_markdown (lua_State *L)
{
  lua_newtable(L);
  luaL_register(L, NULL, fns);
  return 1;
}
