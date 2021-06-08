const express = require('express')
const mongoose = require('mongoose')
const methodOveride = require('method-override')
const Article = require('./models/article')
const articleRouter = require('./routes/articles')
const app = express()

mongoose.connect('mongodb://localhost/blog', {
    useNewUrlParser: true,
    useUnifiedTopology: true,
    useCreateIndex: true
})
    .then(() => console.log('MongoDB Connected'))
    .catch(() => console.log('MongoDB connection Failed'))

app.set('view engine', 'ejs')
app.use(express.static('public'))
app.use(express.urlencoded({ extended: false }))
app.use(methodOveride('_method'))

app.use('/articles', articleRouter)

app.get('/', async (req, res) => {
    const articles = await Article.find().sort({ createdAt: 'desc' })
    
    res.render('articles/index', { articles: articles })
})

app.listen(5000)
