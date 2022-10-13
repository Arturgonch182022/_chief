import org.telegram.telegrambots.ApiContextInitializer
import org.telegram.telegrambots.bots.TelegramLongPollingBot
import org.telegram.telegrambots.meta.TelegramBotsApi
import org.telegram.telegrambots.meta.api.methods.send.SendMessage
import org.telegram.telegrambots.meta.api.objects.Update
import org.telegram.telegrambots.meta.api.objects.replykeyboard.ReplyKeyboardMarkup
import org.telegram.telegrambots.meta.api.objects.replykeyboard.buttons.KeyboardButton
import org.telegram.telegrambots.meta.api.objects.replykeyboard.buttons.KeyboardRow

class TelegramBotApplication

fun main(){
    ApiContextInitializer.init()
    val bot = Bot()
    TelegramBotsApi().registerBot(bot)
}

class Bot: TelegramLongPollingBot() {
    override fun getBotToken() = "5504974129:AAHqoRGZLS7z4WW6QwDvv5UDx5Hf42a5FCo"

    override fun getBotUsername() = "C_h_i_e_f_bot"

    override fun onUpdateReceived(update: Update) {
        if (update.message.text == "/start"){
            execute(SendMessage().setChatId(update.message.chatId).setText("HI"))
        }
        if (update.message.text == "/currency"){
            val keyboard = ReplyKeyboardMarkup()
            listOf(
                KeyboardRow().apply {
                    add(KeyboardButton( "Usd"))
                },
                KeyboardRow().apply {
                            add(KeyboardButton( "Eur"))
                }
            )
            execute(SendMessage()
                .setReplyMarkup(keyboard)
                .setChatId(update.message.chatId)
                .setText("Choose"))
        }



        if (update.message.text == "/time") {
            execute(SendMessage().setChatId(update.message.chatId).setText("evening"))
        }
    }
}