local test = require("santoku.test")
local serialize = require("santoku.serialize") -- luacheck: ignore
local md = require("santoku.markdown")

test("md", function ()
  assert(md.to_html([[
# Title
Some text
- One
- Two
## Subtitle
1. Hello
2. World
  ]]) == [[
<h1>Title</h1>

<p>Some text
- One
- Two</p>

<h2>Subtitle</h2>

<ol>
<li>Hello</li>
<li>World</li>
</ol>
]])
end)
