// Video Link:  https://www.youtube.com/watch?v=SLpUKAGnm-g

const express = require('express')
const mongoose = require('mongoose')
const ShortURL = require('./models/short-url')
const app = express()

mongoose.connect('mongodb://localhost/url-shortner', {
    useNewUrlParser: true,
    useUnifiedTopology: true
})
    .then(() => console.log('Mongodb Connected'))
    .catch(err => console.error(err))

app.set('view engine', 'ejs')
app.use(express.static('public'))
app.use(express.urlencoded({ extended: false }))

app.get('/', async (req, res) => {
    const URLs = await ShortURL.find()

    res.render('index', { URLs: URLs })
})

app.post('/short-url', async (req, res) => {
    await ShortURL.create({ full: req.body['full-url'] })

    res.redirect('/')
})

app.get('/:shorturl', async (req, res) => {
    const url = await ShortURL.findOne({ short: req.params['shorturl'] })

    if (url == null) return res.sendStatus(404)

    url.clicks++
    url.save()
    
    res.redirect(url.full)
})

app.listen(5000, () => console.log('Server started'))
