// Video Link:  https://www.youtube.com/watch?v=H5ObmDUjKV4

require('dotenv').config()

const nightmare = require('nightmare')()
const sgmail = require('@sendgrid/mail')

sgmail.setApiKey(process.env.SENDGRID_API_KEY)

const args = process.argv.slice(2)
const url = args[0]
const minPrice = args[1]

// $169
// https://www.amazon.com/Samsung-Inch-Internal-MZ-76E1T0B-AM/dp/B078DPCY3T

chkPrice()

async function chkPrice() {
    try {
        const princeString = await nightmare
            .goto(url)
            .wait('#priceblock_ourprice')
            .evaluate(() => document.getElementById('priceblock_ourprice').innerText)
            .end()

        const price = parseFloat(princeString.repace('$', ''))
        
        if (minPrice < 200) {
            console.log('It\'s cheep')
            await sendEmail(
                'Price is low',
                `The price on ${url} has droped below ${minPrice}`
            )
        }
        else
            console.log('It\'s expensive')
    } catch (err) {
        await sendEmail('Amazon Price checker Error', err.message)
        throw e
    }

}

function sendEmail(subject, body) {
    const email = {
        to: 'detaci4050@emailhost99.com',
        from: 'amazon-price-checker@example.com',
        subject: subject,
        text: body,
        html: body
    }

    return sgmail.send(email)
}
