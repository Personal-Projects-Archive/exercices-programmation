# Premier exemple
import asyncio

async def envoyer_sms(nom, phone):
    print(f"Envoie d'un sms à {nom} au numéro {phone}")
    await asyncio.sleep(2)
    print("SMS envoyé")

async def main():
    await asyncio.gather(
        envoyer_sms("Alice", "1234-567-890"),
        envoyer_sms("Bob", "0987-654-321")
    )
asyncio.run(main())


# Deuxième exemple
import aiohttp
import asyncio
async def recuperer_contenu():
    url = "https://api.itsasync.fr/share/all"
    session = aiohttp.ClientSession()
    response = await session.get(url)
    if response.status == 200:
        print("Contenu récupéré avec succès")
        data = await response.json()
        print(data)
    else : 
        print(f"Erreur Http {response.status}")
    await response.release()
    await session.close()
asyncio.run(recuperer_contenu())
