import express from "express"
import path from "path"

const app = express()
const port = 3000

app.use(express.static('public'));

app.use((req, res, next) => {
   console.log(req.url);
   next()
})

app.get('/', (req, res) => {
  res.sendFile(path.resolve("public/index.html"))
})

app.get('/user', (req, res) => {
   res.send("Hello user")
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})
