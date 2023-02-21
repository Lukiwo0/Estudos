    function github() {
        window.open('https://github.com/Lukiwo0/Estudos')
    }

    // Conversão para milissegundos
    function converter0() {
        var mili = document.getElementById('mili') 

        if (!mili.value) {
            alert('Você deve colocar um valor. (Se já tiver um valor, tem um espaço depois dele)')
        } else if (Number(mili.value) == Number(0)) {
            alert('Coloque um valor maior que 0.')
        } else {

            var restsegundo = Number(mili.value) / 1000
            var restminuto = Number(mili.value) / 60000
            var resthoras = Number(mili.value) / 36000000
            var restdias = Number(mili.value) / 86400000
            var restsemanas = Number(mili.value) / 604800000

            res0.innerHTML = `O resultado é <strong>${restsegundo} em segundo(s)</strong>!
            <br> O resultado é <strong>${restminuto} em minuto(s)</strong>!
            <br> O resultado é <strong>${resthoras} em hora(s)</strong>!
            <br> O resultado é <strong>${restdias} em dia(s)</strong>!
            <br> O resultado é <strong>${restsemanas} em semana(s)</strong>!`
        }
    }
    // Conversão para segundos
    function converter1() {
        var segundo = document.getElementById('seg') // Criei um var da input

    if (!segundo.value) {
        alert('Você deve colocar um valor. (Se já tiver um valor, tem um espaço depois dele)')
    } else if (Number(segundo.value) == Number(0)) /*  Verificando se o valor é 0 */ {
        alert('Coloque um valor maior que 0.') // Se for, manda um alerta
    } else {
        /* Pegando o valor e fazendo a conta */
        /* Converta segundos em milissegundos */
        var restmili = Number(segundo.value) * 1000
        /* Converta segundos em minutos */
        var restsegundo = Number(segundo.value) / 60
        /* Converta segundos em horas */
        var resthoras = Number(segundo.value) / 3600
        /* Converta segundos em dias */
        var restdias = Number(segundo.value) / 86400
        /* Converta segundos em semanas */
        var restsemanas = Number(segundo.value) / 604800

        /* Mensagem com o resultado*/
        res1.innerHTML = `O resultado é <strong>${restmili} em milissegundos(s)</strong>!
        <br>O resultado é <strong>${restsegundo} em minuto(s)</strong>!
        <br>O resultado é <strong>${resthoras} em hora(s)</strong>!
        <br>O resultado é <strong>${restdias} em dia(s)</strong>!
        <br>O resultado é <strong>${restsemanas} em semana(s)</strong>!`
    }
}

    // Conversão para minutos
    function converter2() {
        var minuto = document.getElementById('min')

    if (!minuto.value) {
            alert('Você deve colocar um valor. (Se já tiver um valor, tem um espaço depois dele')
    } else if (Number(min.value) == Number(0)) {
        alert('Coloque um valor maior que 0.')
    } else {
        var restmili = Number(min.value) * 60000
        var restsegundo = Number(min.value) * 60
        var resthoras = Number(min.value) / 60
        var restdias = Number(min.value) / 1440 
        var restsemanas = Number(min.value) / 10080

        res2.innerHTML = `O resultado é <strong>${restmili} em milissegundo(s)</strong>!
        <br>O resultado é <strong>${restsegundo} em segundo(s)</strong>!
        <br>O resultado é <strong>${resthoras} em hora(s)</strong>!
        <br>O resultado é <strong>${restdias} em dia(s)</strong>!
        <br>O resultado é <strong>${restsemanas} em semana(s)</strong>!`
    }
    }

    // Conversão para horas
    function converter3() {
        var hora = document.getElementById('hora')

    if (!hora.value) {
        alert('Você deve colocar um valor. (Se já tiver um valor, tem um espaço depois dele)')
    } else if (Number(hora.value) == Number(0)) {
        alert('Coloque um valor maior que 0.')
    } else {
        var restmili = Number(hora.value) * 3600000
        var restsegundo = Number(hora.value) * 3600
        var resthoras = Number(hora.value) * 60
        var restdias = Number(hora.value) / 24
        var restsemanas = Number(hora.value) / 168

        res3.innerHTML = `O resultado é <strong>${restmili} em milissegundo(s)</strong>!
        <br>O resultado é <strong>${restsegundo} em segundo(s)</strong>!
        <br>O resultado é <strong>${resthoras} em minuto(s)</strong>!
        <br>O resultado é <strong>${restdias} em dia(s)</strong>!
        <br>O resultado é <strong>${restsemanas} em semana(s)</strong>!`
    }
    }

    // Conversão para dias
    function converter4() {
        var dia = document.getElementById('dia')

    if (!dia.value) {
        alert('Você deve colocar um valor. (Se já tiver um valor, tem um espaço depois dele)')
    } else if (Number(dia.value) == Number(0)) {
        alert('Coloque um valor maior que 0.')
    } else {
        var restmili = Number(dia.value) * 86400000
        var restsegundo = Number(dia.value) * 86400
        var resthoras = Number(dia.value) * 1440
        var restdias = Number(dia.value) * 24
        var restsemanas = Number(dia.value) / 7

        res4.innerHTML = `O resultado é <strong>${restmili} em milissegundo(s)</strong>!
        <br>O resultado é <strong>${restsegundo} em segundo(s)</strong>!
        <br>O resultado é <strong>${resthoras} em minuto(s)</strong>!
        <br>O resultado é <strong>${restdias} em hora(s)</strong>!
        <br>O resultado é <strong>${restsemanas} em semana(s)</strong>!`
    }
    }

    // Conversão para semanas
    function converter5() {
        var semana = document.getElementById('sem')

    if (!semana.value) {
        alert('Você deve colocar um valor. (Se já tiver um valor, tem um espaço depois dele)')
    } else if (Number(semana.value) == Number(0)) {
        alert('Coloque um valor maior que 0.')
    } else {
        var restmili = Number(semana.value) * 604800000
        var restsegundo = Number(semana.value) * 604800
        var restminutos = Number(semana.value) * 10080
        var resthoras = Number(semana.value) * 168
        var restdias = Number(semana.value) * 7

        res5.innerHTML = `O resultado é <strong>${restmili} em milissegundo(s)</strong>!
        <br>O resultado é <strong>${restsegundo} em segundo(s)</strong>!
        <br>O resultado é <strong>${restminutos} em minuto(s)</strong>!
        <br>O resultado é <strong>${resthoras} em hora(s)</strong>!
        <br>O resultado é <strong>${restdias} em dia(s)</strong>!`
    }
    }

    function converter6() {
        document.getElementById('mili').value = ''
        document.getElementById('seg').value = ''
        document.getElementById('min').value = ''
        document.getElementById('hora').value = ''
        document.getElementById('dia').value = ''
        document.getElementById('semana').value = ''
        res0.innerHTML = ''
        res1.innerHTML = ''
        res2.innerHTML = ''
        res3.innerHTML = ''
        res4.innerHTML = ''
        res5.innerHTML = ''
        
    }