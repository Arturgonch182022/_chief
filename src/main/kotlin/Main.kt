import com.github.kotlintelegrambot.bot
import com.github.kotlintelegrambot.dispatch
import com.github.kotlintelegrambot.dispatcher.command
import com.github.kotlintelegrambot.dispatcher.text
import com.github.kotlintelegrambot.entities.ChatId
import com.squareup.moshi.Moshi
import com.squareup.moshi.Types
import com.squareup.moshi.kotlin.reflect.KotlinJsonAdapterFactory
import okhttp3.OkHttpClient
import okhttp3.Request

const val BOT_TOKEN = "5504974129:AAHqoRGZLS7z4WW6QwDvv5UDx5Hf42a5FCo"
val moshi: Moshi = Moshi.Builder().addLast(KotlinJsonAdapterFactory()).build()

data class CurrencyInfo(
    val Cur_Abbreviation: String,
    val Cur_Scale: Int,
    val Cur_OfficialRate: Double
)

fun serveBot() {
    val bot = bot {
        token = BOT_TOKEN
        dispatch {
            command("start") {
                bot.sendMessage(ChatId.fromId(message.chat.id), text = "Hello, please type currency")
                update.consume()//если это команда заработала , то следующая не будет
            }
            text {
                for (info in getInfo()) {
                    if (info.Cur_Abbreviation.equals(text, ignoreCase = true) && info.Cur_Scale != 1) {
                         //info.Cur_OfficialRate.toString()
                        bot.sendMessage(ChatId.fromId(message.chat.id), text = "${info.Cur_Scale} ${info.Cur_Abbreviation.toString()}  ->  ${info.Cur_OfficialRate.toString()} BYN")
                        return@text
                    }

                    if (info.Cur_Abbreviation.equals(text, ignoreCase = true)) {
                        bot.sendMessage(ChatId.fromId(message.chat.id), text = info.Cur_OfficialRate.toString())
                        return@text
                    }
                }
                bot.sendMessage(ChatId.fromId(message.chat.id), text = "No such currency")
            }
        }
    }
    bot.startPolling()
}

fun getInfo(): List<CurrencyInfo> {
    // OkHttp
    val client: OkHttpClient = OkHttpClient.Builder().build()// кто запрос запрашивает
    val request = Request.Builder().url("https://www.nbrb.by/api/exrates/rates?periodicity=0").get().build()// откуда
    val resp = client.newCall(request).execute() // получаем запрос
    val text = resp.body()!!.string()//  переводим в строку
    println(text)//
    // Moshi
    val typeList = Types.newParameterizedType(List::class.java, CurrencyInfo::class.java)
    val adapter = moshi.adapter<List<CurrencyInfo>>(typeList)
    val info: List<CurrencyInfo>? = adapter.fromJson(text)
    println(info)
//    if (info != null) {
//        return info
//    } else {
//        return listOf()
//    }
    return info ?: listOf()
}

// [
// {"Cur_Abbreviation": "USD", "Cur_OfficialRate": 2.4},
// {"Cur_Abbreviation": "RUB", "Cur_OfficialRate": 2.8}
// ]


// USD
// 2.5

// RUB
// 100 RUB -> 3.4 BYN

fun main() {
    serveBot()
}