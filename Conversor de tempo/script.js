    // Conversão para segundos
    function converter1() {
        var segundo = document.getElementById('seg') // Criei um var da input
        var limete = 1000000 // O maior número que a pessoa pode colocar é 100 mil
        

    if (Number(segundo.value) > limete) /* Verificando se o valor é maior que 100 mil */ {
        window.alert('Ok, isso é um número muito grande, tente colocar um menor.') // Se for, manda um alerta
    } else if (Number(segundo.value) == Number(0)) /*  Verificando se o valor é 0 */ {
        window.alert('Coloque um valor maior que 0.') // Se for, manda um alerta
    } else {
        /* Pegando o valor e fazendo a conta */
        /* Converta segundos em minutos */
        var restsegundo1 = Number(segundo.value) / 60
        /* Converta minutos em horas */
        var resthoras1 = Number(segundo.value) / 3600
        /* Converta horas em minutos */
        var restsdias1 = Number(segundo.value) / 86400

        /* Mensagem com o resultado*/
        res1.innerHTML = `O resultado é <strong>${restsegundo1} em minuto(s)</strong>!
        <br>O resultado é <strong>${resthoras1} em hora(s)</strong>!
        <br>O resultado é <strong>${restsdias1} em dia(s)</strong>!`
    }
}

    // Conversão para minutos
    function converter2() {
        var minuto = document.getElementById('min')
        var limete = 1000000

    if (Number(min.value) > limete) {
        window.alert('Ok, isso é um número muito grande, tente colocar um menor.')
    } else if (Number(min.value) == Number(0)) {
        window.alert('Coloque um valor maior que 0.')
    } else {
        var restsegundo2 = Number(min.value) * 60
        var resthoras1 = Number(min.value) / 60
        var restsdias1 = Number(min.value) / 1440 

        res2.innerHTML = `O resultado é <strong>${restsegundo2} em segundo(s)</strong>!
        <br>O resultado é <strong>${resthoras1} em horas</strong>!
        <br>O resultado é <strong>${restsdias1} em dias</strong>!`
    }
    }

    // Conversão para horas
    function converter3() {
        var hora = document.getElementById('hora')
        var limete = 1000000

    if (Number(hora.value) > limete) {
        window.alert('Ok, isso é um número muito grande, tente colocar um menor.')
    } else if (Number(hora.value) == Number(0)) {
        window.alert('Coloque um valor maior que 0.')
    } else {
        var restsegundo2 = Number(hora.value) * 3600
        var resthoras1 = Number(hora.value) * 60
        var restsdias1 = Number(hora.value) / 24

        res3.innerHTML = `O resultado é <strong>${restsegundo2} em segundo(s)</strong>!
        <br>O resultado é <strong>${resthoras1} em minuto(s)</strong>!
        <br>O resultado é <strong>${restsdias1} em dia(s)</strong>!`
    }
    }

    // Conversão para dias
    function converter4() {
        var dia = document.getElementById('dia')
        var limete = 1000000

    if (Number(dia.value) > limete) {
        window.alert('Ok, isso é um número muito grande, tente colocar um menor.')
    } else if (Number(dia.value) == Number(0)) {
        window.alert('Coloque um valor maior que 0.')
    } else {
        var restsegundo2 = Number(dia.value) * 86400
        var resthoras1 = Number(dia.value) * 1440
        var restsdias1 = Number(dia.value) * 24

        res4.innerHTML = `O resultado é <strong>${restsegundo2} em segundo(s)</strong>!
        <br>O resultado é <strong>${resthoras1} em minuto(s)</strong>!
        <br>O resultado é <strong>${restsdias1} em hora(s)</strong>!`
    }
    }